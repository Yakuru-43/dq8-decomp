# func_0029CDA0 — CLASS structural score=12 (12 words differ, 92 vs 92 bytes)

Best of 8 attempts, ~25 min, factory-2 session 2026-10-25 (08:31–08:56).
Size 96 (0x60), bin SLES_539.74, `// range: 0x29CDA0 0x29CE00`,
TU guess `dq_monster_ai.cpp?`. Best C: `notes/needs-claude/func_0029CDA0_best.c`
(untracked) — four different source shapes all compiled to this same layout.

## What it does
`arg0` is an object with a pointer at +0x488 to a node with two flag bytes
and a pointer at +0x1C; the tail calls `func_00297090(node, arg1)` and
returns `> 0`:

```
v1 = *(u8 **)(arg0 + 0x488);           // lw $v1,0x488($a0)
if (v1[0] == 0) return 0;              // lbu + beql →epilogue, daddu v0=0 delay
if (v1[1] != 0) return 0;              // lbu + bnel →epilogue, daddu v0=0 delay
ref = *(u8 **)(v1 + 0x1C);             // lw $a0,0x1C($v1)
if (*(s32 *)(ref+0x140) < *(s32 *)(ref+0x144))  // lw lw; slt $v0,$v1,$v0
    return func_00297090(ref, arg1) > 0;         // bnez →jal; slt $v0,$zero,$v0
return 0;                                     // else: b →epilogue, daddu delay
```

`func_00297090` = tail thunk of `func_00201760(a0, 0)`; the call must pass
the parameter `$a1` through untouched (a literal `0`/NULL second arg adds a
`daddu $a1`), same lesson as `func_0029CC00`.

## Original (asm/SLES_539.74/game_29CB00.s)
```
+008 lw $v1,0x488($a0) ; +00C lbu $v0,0($v1)
+010 beql →+050 ; +014 daddu $v0,$zero,$zero
+018 lbu $v0,1($v1) ; +01C bnel →+050 ; +020 daddu $v0,$zero,$zero
+024 lw $a0,0x1C($v1) ; +028 lw $v1,0x140($a0) ; +02C lw $v0,0x144($a0)
+030 slt $v0,$v1,$v0 ; +034 bnez →+044 ; +038 nop
+03C b →+050 ; +040 daddu $v0,$zero,$zero
+044 jal func_00297090 ; +048 nop ; +04C slt $v0,$zero,$v0
+050 ld $ra,0($sp) ; jr $ra ; addiu $sp,$sp,0x10
```

## Best C (score 12) — everything right except two block layouts
Guards 1, prologue and epilogue exact. Diffs, both in the scheduler's block
orientation (instruction multiset is ~identical, only order/branch polarity):
```
+01C mine: beql →+028, delay lw $a0 ; +024 b →+050, delay daddu   (orig: bnel→epilogue)
+034 mine: slt $at,$v1,$v0 ; beql $at →+050, delay daddu, fall→jal  (orig: slt $v0; bnez →+044)
```

## What was tried (all gave the score-12 layout unless noted)
1. `u8 *` casts, guards as separate early-return `if`s — score 12.
2. `ref` (=node) loaded **before** the guards — score 17 (load hoisted above
   guard 1, `beqz` + missing delay daddu, +4 bytes).
3. Explicit `else { return 0; }` — same as 1.
4. Named `s32 ok = a < b; if (ok != 0)` — same as 1.
5. `static inline s32 Below(...)` helper returning the compare — same as 1.
6. Fully typed structs (`S_owner`/`S_node`/`S_ref`) — same as 1.
7. Combined guard `if (v1->flag0 == 0 || v1->flag1 != 0) return 0;` —
   score 17: both guards became plain `beqz`/`bnez` with `nop` delay slots
   and a shared `daddu` after the epilogue jump; the whole tail shifted.
8. Shared suffix `if (cmp) ret = call(); else ret = 0; return ret > 0;` —
   score 17, CW folded to 88 bytes.

`tools/permute.py func_0029CDA0 --bin SLES_539.74 --run 240` failed in this
worktree: `FileNotFoundError: 'cpp'` (no C preprocessor on PATH), so the
finisher could not run. The remaining diff looks like pure block-order +
branch polarity, which is the permuter's territory — worth a rerun where
`cpp` exists.
