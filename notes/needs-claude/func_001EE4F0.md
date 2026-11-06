# func_001EE4F0

CLASS structural score=14 (12 words differ, 64 vs 56 bytes) — best attempt (`if (r == 0) return 0;` form)

Size 64 B (0x1EE4F0–0x1EE530, real code 56 B + 8 B padding). Leaf-with-frame
function: `r = func_00166760(); if (!r) return 0; func_001340C0(&D_00414E30, r); return 1;`
(D_00414E30 is loaded `lui/addiu %hi/%lo`, not gp-relative.)

## Original shape (what is wanted)
```
jal func_166760; nop
beql $v0,$zero,.L_epi       <- zero path jumps FORWARD to the shared epilogue
 daddu $v0,$zero,$zero      <- return 0 materialized in the delay slot
lui $a0,%hi(D_00414E30)
daddu $a1,$v0,$zero
jal func_1340C0; addiu $a0,$a0,%lo(D_00414E30)
addiu $v0,$zero,1           <- then falls through into the single epilogue
.L_epi: ld $ra; jr $ra; addiu $sp; nop; nop
```
Mine keeps inverting it: CW emits `bnez $v0,<body>` + `nop`, then a private
zero stub `b <epi>; daddu $v0,$zero,$zero`, so the body lands one word too
late and one word too long (64 B of real code vs 56).

## Best C (attempt 1, total 64 B vs orig 56 B)
```c
M2C_UNK func_001340C0(M2C_UNK *, s32);              /* extern */
s32 func_00166760();                                /* extern */
extern M2C_UNK D_00414E30 __attribute__((section(".data")));

s32 func_001EE4F0(void) {
    s32 r;

    r = func_00166760();
    if (r == 0) {
        return 0;
    }
    func_001340C0(&D_00414E30, r);
    return 1;
}
```

## Tried
- idiom `notes/idioms.md` "Call guard `jal f; beql $v0,$zero,<epi>; daddu $v0,$zero,$zero`
  then the second call inline" (`if (!r) { r = 0; } else { r = g(...); } return r;`):
  no change, CW still bnez-inverts + private stub (score 16, 68 B).
- Same with the arms swapped (`if (r != 0) { call; r = 1; } else { r = 0; } return r;`):
  identical output, score 16.
- idiom `notes/idioms-new/func_002204C0.md` (materialize result first): sign does not
  fit (no return-variable compare here).
- `tools/permute.py func_001EE4F0 --run 200` fails in this worktree:
  `FileNotFoundError: 'cpp'` (the tool shells out to `cpp`, not on PATH here).

MH2 entries checked: none in the Index matched "branch-likely vs inverted test on a
call result to a shared epilogue".
