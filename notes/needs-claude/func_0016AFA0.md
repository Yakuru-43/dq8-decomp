# func_0016AFA0 — needs-claude

CLASS structural score=51 (45 words differ, 372 vs 348 bytes) — best attempt.

- Size: 352 B (348 code + 4 pad). Asm: `asm/SLES_539.74/game_16AE20.s:128-232`
  (three split files carry the glabel; game_16AE20.s is the one whose neighbours fit).
- Best C: `notes/needs-claude/func_0016AFA0_best.cpp` (kept OUT of src/, compiles,
  semantics right, 372 vs 348 bytes).

## What it does
Entry setter on the object's entry table at `obj + 0x3864` (60-byte entries,
count at `obj + 0x3860`, word0 = state, name chars at +8, data ptr at +0x38,
vptr at +0x34). `idx < 0` → scan the array for an entry whose word0 == 0 and
return -1 (every scan path returns -1); else range-check, call the first
virtual (`lw $t9,0x34; lw $t9,8; jalr`), `state = 0`, `data = arg2`, copy
`name` with `func_001340C0` (default `D_003DFBD0`, null name also zeroes
byte 8), `state |= 4`; `obj->[0x44B4] = idx` if it is < 0; return `idx` or -1
via a `flag` join. Neighbours `func_0016B2F0.c` / `func_0016B6F0.c` have the
same `get_3864` shape — copied from there.

## Prologue + guards already byte-exact
Both entry `bltz $s3` branches, the count load + `slt`/`beqz`, the strength-
reduced `idx * 0x3C` address math, the `beql $s0` null return, the virtual
call, `sw $zero,0($s0)`, `sw $s2,0x38`, the `jal func_001340C0` + `addiu $a0,
$s0,0x8`, the lw/ori/sw `|= 4`, and the scan-loop skeleton (helper null joins,
bottom test in `$v1`, counter in `$a1`) all match.

## The four remaining diffs
1. **`if (name == NULL) name = D_003DFBD0;`** — orig: `beql $s1,$zero,+8` +
   delay `addiu $s1, $gp, %gp_rel(D_003DFBD0)` (one-word gp-relative).
   Mine emits `lui`/`addiu %hi/%lo` (two words) so CW gives up on the delay
   slot and emits `beqz s1, <far>; nop` with the store out of line. Fix the
   extern so it links gp-relative (see idiom `section(".data")`, idioms.md:883,
   which is the reverse case — maybe it must NOT have a section attr in a
   `.cpp`, or the C++ path drops gp-rel for extern arrays).
2. **`if (obj->[0x44B4] < 0) obj->[0x44B4] = idx;`** — orig: `bltzl $v0,+8`
   with `sw $s3, 0x44B4($a0)` in the delay slot. Mine: plain `bltz` to a cold
   block, `addiu $v1, $a0, 0x44B4` in the delay slot and `sw $s3, 0($v1)`
   out of line (pointer local, like the func_0016B2F0 idioms). Probably a
   consequence of (1)'s schedule; try fixing (1) first.
3. **Scan test `lw $v0,0($v0)` + `xor $v0,$v0,$zero; sltiu $v0,$v0,1;
   bnez $v0, <cold -1 stub>`** (idioms.md:241 shape `B() == 0` where B is a
   static inline s32 returning 0/1). Mine folded `entry_state(e) == 0` to a
   bare `bnez` and placed the `-1` inline instead of cold.
4. **Tail**: orig `beql $v1,$zero,<epi>; addiu $v0,-1` then `b <epi>;
   daddu $v0,$s3,$zero` (i.e. `if (flag == 0) { return -1; } return idx;`).
   Mine inverted to `bnel $v1,$zero,<idx-return>; move v0,s3` + fall-through
   `li v0,-1`. Same semantics; try the `flag` as `s32 flag = -1;` declared at
   the top with the assignment only in the `data != 0` arm (idiom func_00164EB0).

## Tried
2 try_match attempts (both `-O3`). Idioms used: idioms.md:199 (`$t9` virtual,
vptr at data end — correct first try), idioms-new/func_00164EB0.md (the double
`bltz` guard shape — matched), idioms-new/func_00159EB0.md (context),
idioms.md:241 (xor/sltiu — not reproduced yet, see 3). mh2 index (rule 8) not
read: session time ran out before a second near-miss attempt.
