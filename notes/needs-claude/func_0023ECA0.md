# func_0023ECA0 — needs-claude

CLASS structural score=47 (46 words differ, 212 vs 216 bytes)
(best attempt; register-only-looking diffs from +0x10, see "What differs")

- Size: 224 B (0x23ECA0..0x23ED80), bin SLES_539.74, `asm/SLES_539.74/game_23E680.s`
- Best C: `notes/needs-claude/func_0023ECA0_best.c`
- Script-command function, sibling of `func_0023DB90`/`func_0023D870`
  (same `Arg`/`Value`/`D_003E0B24` family, see src files).

## What it does (confident reconstruction)

`s32 func_0023ECA0(Arg *args, s32 kind)`:
1. `target = D_003E0B24->field8` (offset 8 in the global's struct, NOT the
   `slots`/`count` of the sibling files); `if (target == 0) return 0;`
2. `v0val = args[0].value.i` unconditionally (no tag check — callee
   `func_001EA0A0(target, v0val, a2)` must do the tag dispatch);
3. `f = -1.0f` default; if `kind >= 2`: read `ap = &args[1]`:
   `if (ap->tag != 0) f = ap->value.f; else f = (f32)ap->value.i;` then
   the pointer advances to `&args[2]` (asm: `addiu $a0, $v1, 0x8` in the
   tag-test `bnez` delay slot, so the advance happens in BOTH arms);
4. if `kind >= 3`: `a2 = (ap->tag == 1) ? (s32)ap->value.f : ap->value.i;`
   (this block matches byte-exact in my best attempt);
5. `func_001EA0A0(target, v0val, a2);` then
   `if (f >= 0.0f) func_00288A70(D_003E0B24->field8, 1, f);` (`f >= 0` as
   `c.lt.s $f20, $f0` + `bc1fl`, f0 materialized by `mtc1 $zero`; the
   `lw $v0, %gp(D_003E0B24)` reload sits in the `bc1fl` delay slot),
   then `return 1;` from one stub (`b ED68; addiu $v0, $zero, 1`).

Callees: `func_001EA0A0` = thunk to `func_001E76D0(a0+0x1F0)`,
`func_00288A70` = thunk to `func_001E77F0(a0+0x1F0, -1, a1, a3)`; both
already in `src/`. Float arg goes via `$f12` (`mov.s $f12, $f20`).
`$ra` saved with `sd 0x10($sp)`, `$f20` with `swc1 0($sp)`.

## What differs from the best attempt

From +0x10 on, colors + one missing word (212 vs 216):
- original keeps `target` in `$a3` and `v0val` in `$t0`; mine gets them
  swapped (`$t0`/`$a3`).
- original computes `addiu $v1, $a0, 0x8` (&args[1]) early, loads the tag
  and both float values through `$v1`, and materializes the advance into
  `$a0` (`daddu $a0,$v1` in the `kind<2` `bnez` delay, `addiu $a0,$v1,8`
  in the tag `bnez` delay). Mine coalesces to one `$a0` register and the
  scheduler moves `ap++` AFTER the arms instead of into the delay slot —
  so mine loses the `b join; cvt.s.w` shape (int arm: `lwc1 $f0; b; cvt`
  + separate `lwc1 $f20` branch target) and saves 4 bytes.
- `a2 = 0` position: original `+0x2C` (before the `slti`), mine in the
  `bnez` delay slot.
- the `beql`/`bnez` polarity of the kind>=2 tag test flips with the arm
  swap; only the `bnez`-to-float-arm form reproduces the delay-slot
  `addiu`.

## What was tried

- Neighbour style (`func_0023DB90` ternary `(tag==1)?(s32)f:i` — the
  kind>=3 block reproduces exactly with it).
- `ap` as single pointer (`ap++`, `ap = &args[2]`, `ap = &ap[1]`), loads
  via `ap` vs via `args[1]`; `bp = &args[1]` / `bp = &args[2]` two-pointer
  variant (coalesced away by CW, no change).
- Both if-arm orders for the tag test.
- Guard clause + single return stub (`return 1` after if/else): the tail
  (call, `c.lt.s` guard, `func_00288A70`, stub) already matches modulo the
  `lw $v0` delay slot.
- `tools/permute.py func_0023ECA0 --run 600` fails here: `FileNotFoundError:
  cpp` (no system cpp in this worktree's PATH) — the permuter never started.
- MH2 catalogue: not consulted (index not read; time budget).

Suggested next step: get `permute.py` running (fix the `cpp` path, e.g.
under `.toolchain/wibo` or a system `clang -E` shim) — the remaining diff
is pure scheduler/coloring on an otherwise-identical instruction stream.
