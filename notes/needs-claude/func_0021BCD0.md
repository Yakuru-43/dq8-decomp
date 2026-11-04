# func_0021BCD0 — vertex format converter with VU0 macro instructions

CLASS structural score=93 (90 words differ, 372 vs 384 bytes) — VU0 macro
instructions in the two quantising loops; statement `asm {}` emits them but
the scheduler/register allocator then diverges everywhere (see "What I tried").

- Size: 384 bytes (0x21BCD0..0x21BE4C + pad to 0x21BE50), SLES_539.74.
- Args (o32): `$a0` dst, `$a1` src (vec4 f32 stream), `$a2` count,
  `$a3` format, `$t0` scale (f32[3]). Leaf, frame 0x20: res buffer at sp+0x00
  (sqc2 target, read by `lw 0/4/8($sp)`), scale buffer at sp+0x10.

## What it does

`vec4 f32 -> vec3` stream conversion with three component formats:

- `fmt == 32`: copy 3 of 4 floats per vertex (dst stride 12, src stride 16).
  Loop is `while (i < count)` with `i++` at the body top and
  `lwc1 $f0,0($a1)` in the `bnel` delay slot (first-element preload).
  Preamble `lq $t1,0($t0)` / `sq $t1,0x10($sp)` (in the `bne` delay slot):
  a 16-byte copy of `scale` to sp+0x10 that is **never read** — a dead store
  the original kept; my build dead-store-eliminates it.
- `fmt == 16`: `scl[i] = 32768.0f / scale[i]` (one `lui 0x4700; mtc1 f3`),
  then per vertex: `lqc2 vf16,0(a1)` (src), `lqc2 vf17,0(t1)` (scl),
  `vmul.xyzw`, `vftoi0.xyzw`, `sqc2 vf15,0(t2)`, then `lw` ×3 from sp+0 and
  `sh` ×3 (dst stride 6). i in `$t3`.
- `fmt == 8`: same with `128.0f` (`lui 0x4300`), `sb` ×3, dst stride 3.
- Dispatch is an if/else-if chain: `bne 32`, `bnel 16` with
  `addiu $v1,$zero,8` in its delay slot, `bne 8`.
- Both VU0 loops close with a plain `bnez` + `nop` (no likely form; body
  starts with the asm).

## Best C

notes/needs-claude/func_0021BCD0_best.c — plain C for everything, with a
statement-level `asm { lqc2/vmul.xyzw/vftoi0/sqc2 }` in the two loops.

## What I tried

1. That draft, `try_match -- -O3`: **mwccps2 accepts statement `asm {}` and
   emits the VU0 opcodes** — but CLASS structural, score 93, 372 vs 384 B.
   The compiler treats the block as opaque: it does not know the asm needs
   `$a1`/`$t1`/`$t2` (src/scl/res pointers), nor that `sqc2` writes sp+0x00,
   so it drops the three `lw` reloads (`sb` reads stale regs), places the
   first `lqc2` in the loop branch delay slot, picks `$t6` for the counter,
   and dead-store-eliminates the fmt-32 `lq/sq` scale copy.
2. Prior art says this is the expected wall:
   mh2 catalogue (local copy) "What can't come from C": *VU0 macro
   instructions (lqc2, sqc2, vmul...): MWCC never emits them from C; the
   originals were CodeWarrior `asm` functions*. Also
   notes/needs-claude/func_00229D20.md (pure VU0 -> asmfunc stub). This one
   is mixed: the dispatch + fmt-32 path look like ordinary CW'd C, so the
   original was plausibly C with a per-iteration asm block (or an asm
   function the rest of the compiler scheduled around) — no register
   constraints exist in mwccps2 inline asm, so byte-exactness needs Claude
   (e.g. an asmfunc stub, or a way to pin `$a1/$t1/$t2` and defeat the
   dead-store elim without contrived C).

Queue row left `needs-claude`. No config lines touched; src draft NOT
committed (best C is the `_best.c` beside this note).
