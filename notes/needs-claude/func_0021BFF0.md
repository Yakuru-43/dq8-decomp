CLASS structural score=127 (124 words differ, 680 vs 692 bytes)

# func_0021BFF0 (0x21BFF0, 704 bytes incl. padding, 692 compared)

GS-style packet writer. Params beyond a0-a3 arrive in t-regs (idioms.md
"parameters 5 to 7"): `$t0` = `u16 *` id array, `$t1` = `s32 *` output.

1. First loop: `best = max(arg3[*t0++].n)` over `a2` entries; `arg3` =
   12-byte `struct { u32 w0, w1; s32 n; } *` (a3). A second walk pointer
   (v0) is copied at entry and reused by all three copy loops.
2. Dispatch (matched exactly at +0x44): `if (best == 1) byte-mode
   (0x62000000 tag) else if (best < 3) halfword-mode (0x66000000, covers
   0 and 2) else word-mode (0x6E000000)`.
3. Each mode writes 3 header words at `a0`: `0x01000102`,
   `tag | (a1|0x8000) | (a2<<16)`, and `tag | ((a1+1)|0xC000) | (a2<<16)`
   at the shared "second address" `a0 + 8 + words*4` (words = ceil(a2/2)
   for half, ceil(a2/4) for byte, a2 for word), then copies field 0 /
   field 1 of each entry as s8/u8 (byte), s16/s16 (half), u32/u32 (word)
   into two byte/half/word streams at `a0+8` and `second+4`.
   The byte mode uses `lb` for field 0 and `lbu` for field 4.
   The word-mode loop additionally re-runs the max update
   (`lw 8(t0); slt; beqz delay addiu t2; daddu`) and decrements `a2`
   **last** in the body; half/byte loops decrement `a2` right after the
   `lhu`. All three loop bottoms are plain `bgtz` + `nop` (never
   branch-likely).
4. Shared tail: each arm leaves `end` in `$t2` (word mode: the final
   stream-2 pointer `d2`; half/byte: `second + words*4 + 4`); tail is
   `sw v1,0($t1)` (`*out = best`) then `return (end - arg0) / 4` as
   signed `(x+3)>>2` via `bgez/sra` + `addiu 3/sra`. The half/byte arms
   reach the tail through `sw` at +0x110; the word arm jumps to the
   `subu` with the `sw` in its delay slot.

Best C: `notes/needs-claude/func_0021BFF0_best.c` (compiles, structural
class). With it the function matches **byte-exact from +0x00 to +0x44**
(max loop + dispatch + half-mode division), so the if-chain order, the
division spellings (`words = a2/n; if (a2 % n != 0) words++;`), the
shared second-address local, and the loop shapes are right.

Remaining problems (why it is not a register-only diff yet):
- my total is 680 vs 692: three instructions short. The word-mode loop
  hoists the `lw 8(t0)` (max load) early instead of after the second
  `sw`, which loses one scheduling slot, and one arm's tail costs a
  different shape than the original's shared `sw`-in-delay-slot jump.
- register allocation then cascades: orig keeps `best` in `$v1` and `w`
  in `$t2` (end also `$t2`), mine puts `best` in `$t2`, `w` in `$v0`,
  `end` in `$t4`; `+0x48` beq displacement 0x3C vs 0x3D is just the
  block-size skew.

Tried: `switch` (CW emitted a ==2/==0/==1 chain — wrong dispatch) →
if-chain `best==1 / best<3 / else` (fixed dispatch); `cnt--` at top vs
bottom of the max loop (bottom is right); `p`-copy vs `arg4`-advance;
separate `end` vs shared second-address local (shared is right);
MH2 catalogue not consulted (out of time).

Per-function budget (25 min) hit 2026-11-03 10:27, factory-2.
