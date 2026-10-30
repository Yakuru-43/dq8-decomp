# func_0014ECA0 — needs-claude

Best attempt CLASS: **register-only, score ~10 (10/40 words differ), 160 B size
correct** — only the address-computation prologue (words +0x04..+0x24) differs;
all 30 store words match.

Size 148 B code + 12 B padding (range 0x14ECA0 0x14ED40), refs `D_003ED890`.

## What it does
`arg0` is a 0x30-byte object. Reads selector words at 0x0 (i0) and 0x4 (i4),
indexes a table entry `e = D_003ED890 + i4*0xC0 + i0*0x10`, copies the entry's
words at 0x00/0x04/0x08 into the object at 0x18/0x1C/0x20, then loads
`*(e+0x300)[obj[0x8]]`, `*(e+0x304)[obj[0xC]]`, `*(e+0x308)[obj[0x10]]` into
0x24/0x28/0x2C, and stores 6 at 0x14 (delay slot of the `jr $ra`; the
`addiu $v1,$zero,6` is hoisted to the top).

## Original prologue vs mine
Original (my best gives identical flow, mirrored registers):

    lw   $a2, 0x0($a0)      | lw   $t0, 0x4($a0)   (mine: i4 first, into $t0)
    lui  $a1, %hi(D_003ED890)| lui $a2, ...hi      (mine: base in $a2)
    lw   $a3, 0x4($a0)      | lw   $a1, 0x0($a0)   (mine: i0 into $a1)
    addiu$a1, %lo(D_003ED890)| addiu $a2, ...lo
    addiu$v1, $zero, 0x6    | addiu $v1, $zero, 0x6
    sll  $t0, $a2, 4        | sll  $a3, $t0, 1     (mine: i4*192 chain first)
    sll  $a2, $a3, 1        | ...
    addu $a2, $a2, $a3      |
    sll  $a2, $a2, 6        | sll  $a1, $a1, 4     (mine: i0*16 late)
    addu $a1, $a1, $a2      | addu $a2, $a2, $a3
    addu $a3, $a1, $t0      | addu $a3, $a1, $a2

Original materializes the table base into `$a1` between the two loads, shifts
i0 into `$t0` **before** reusing `$a2` for the i4*192 chain (i4*192 =
`(x<<1 + x) << 6`). Mine loads/starts i4's term first (`(D + i4*0xC0) + i0*0x10`
left-to-right) and ends with the entry in `$a3` like the original, but the
first ten words are register-mirrored (a1↔a2, t0↔a3-ish) and slightly
reordered.

## Tried
- `src/SLES_539.74/func_0014ECA0.c` (best): `M2C_FIELD` byte-offset locals
  `var_a2` (i0), `var_a3` (i4), `new_var = D_003ED890 + var_a3 * 0xC0 +
  var_a2 * 0x10`; indexed loads as `((s32 *) M2C_FIELD(new_var, s32 *, 0x300))
  [M2C_FIELD(arg0, s32 *, 8)]`. Register-only, score ~10. Not committed.
- Splitting the multiplies into locals `var_t0 = var_a2 * 0x10;` (declared
  right after i0's load) `var_a2_2 = var_a3 * 0xC0;` → CLASS **structural
  score=38, 152 vs 148 bytes** (extra scheduling). Reverted.
- `tools/permute.py func_0014ECA0 --run 600` → **crashes**: `FileNotFoundError:
  'cpp'` — the permuter is unusable in this worktree/environment until `cpp`
  is on PATH.

## Ideas
The register-only class is what the permuter is for: fix `cpp` and rerun.
Alternatively the original may be C like `u8 *e = &D_003ED890[i4 * 0xC0];
e += i0 * 0x10;` or a `struct { s32 *p[3]; }` typed access where the base
load is written separately; try a running-pointer local so i0*16 is its first
use.
