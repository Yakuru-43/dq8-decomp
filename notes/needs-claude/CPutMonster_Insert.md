CLASS reorder+register score=5 (5 words differ, 352 vs 352 bytes) — try_match -- -O3, best attempt

# CPutMonster_Insert — func @ 0x00354160, 352 bytes (asm/SLES_539.74/game_353E30.s)

Inserts a record into a 32-entry, 0x30-byte-stride table and debug-prints.
`arg0` = table base, `arg1` = source record (s32 at 0, s16 at 0xC, s16 at 0x10),
`arg2` = index. If `e[arg2].state` is 1, 2 or 4, shift entries up
(`for (i = 31; i > arg2; i--) e[i] = e[i-1]` — byte-exact with my draft,
48 = (i*2+i)<<4, member-wise copy: lw/sw, four lwc1/swc1 at 0x10..0x1C,
three lw/sw at 0x20/0x24/0x28). Then `e[arg2].state = 1`, copy the three
source words, `DebugPrintf(&D_003D3810, arg1, arg2)`, scan all 32 entries
printing `DebugPrintf(&D_003D37F0, i, e[i].id, e[i].field_24)` for each with
state != 0, finally `DebugPrintf(&D_003D37E0)`. Returns void.

## The only diff: register split in the final scan loop (score 5, 5 words)

Original (`$v0` = entry base for the whole loop, `$t0` for the tested state):
```
+0D8  sll   $v0, $s0, 1        (mine identical through +0E0)
+0DC  addu  $v0, $v0, $s0
+0E0  sll   $v0, $v0, 4
+0E4  addu  $v0, $s1, $v0      | mine: addu $v1, $s1, $v0
+0E8  lw    $t0, 0x0($v0)      | mine: lw   $v0, 0x0($v1)
+0EC  bnel  $t0, $zero, +      | mine: bnel $v0, $zero, +
+0F0  lw    $a2, 0x20($v0)     | mine: lw   $a2, 0x20($v1)   (delay slot)
...
+138  lw    $a3, 0x24($v0)     | mine: lw   $a3, 0x24($v1)   (cold print block)
```
Mine keeps the base in `$v1` and the state in `$v0`; the original reuses
`$v0` in place for the base and puts the state in `$t0`. slt/slti forms and
all branches already match. `slti $v0,$s0,0x20`/`bnez` matches, so the
idioms-new "bound one off" entry does not apply.

## Best C (compiled with -- -O3; only the scan loop diverges)

```c
// range: 0x354160 0x3542C0
#include "common.h"

struct PutMonsterPos { f32 x, y, z, w; };
struct PutMonsterEntry {
    s32 state;
    struct PutMonsterPos pos __attribute__((aligned(16)));
    s32 id; s32 field_24; s32 field_28;
};
extern char D_003D37E0[]; extern char D_003D37F0[]; extern char D_003D3810[];
M2C_UNK DebugPrintf();

void CPutMonster_Insert(struct PutMonsterEntry *arg0, char *arg1, s32 arg2) {
    s32 i;
    if (arg0[arg2].state == 1 || arg0[arg2].state == 2 || arg0[arg2].state == 4) {
        for (i = 31; i > arg2; i--) {
            arg0[i].state = arg0[i - 1].state;
            arg0[i].pos = arg0[i - 1].pos;
            arg0[i].id = arg0[i - 1].id;
            arg0[i].field_24 = arg0[i - 1].field_24;
            arg0[i].field_28 = arg0[i - 1].field_28;
        }
    }
    arg0[arg2].state = 1;
    arg0[arg2].id = *(s32 *)arg1;
    arg0[arg2].field_24 = *(s16 *)(arg1 + 0xC);
    arg0[arg2].field_28 = *(s16 *)(arg1 + 0x10);
    DebugPrintf(D_003D3810, arg1, arg2);
    for (i = 0; i < 32; i++) {
        if (arg0[i].state != 0) {
            DebugPrintf(D_003D37F0, i, arg0[i].id, arg0[i].field_24);
        }
    }
    DebugPrintf(D_003D37E0);
}
```

The `__attribute__((aligned(16)))` on `pos` gives the exact
lw/sw + 4x lwc1/swc1 + 3x lw/sw member-wise copy (per idioms.md "Struct
copies show the member types"); a plain `*dst = *src` was not tried because
idioms-new/func_00313A70.md warns it coalesces to a word loop.

## Tried
- Initial draft from raw asm: score 5 reorder+register immediately; shift
  loop and state-check chain byte-exact on the first attempt.
- Named pointer local `e = &arg0[i]` for the scan-loop entry: no change
  (same 5-word register diff).
- `tools/permute.py CPutMonster_Insert --run 600` could not run: it dies in
  subprocess with `FileNotFoundError: 'cpp'` (this worktree's PATH has no
  cpp; build/permute/CPutMonster_Insert was created before the crash). The
  register-only finisher is what this function needs.
- No mh2 catalogue entry read: the diff is register allocation only and the
  idioms.md register-cluster entries did not fit (no commutative operand at
  the divergence).

## Ideas for Claude
- `$t0` for the test value suggests the load is materialized in a scratch
  reg where mine keeps `$v0`: maybe the original tests through a second
  read (`if (arg0[i].state)` where the value is not kept as a named SSA
  value), or CW picks `$t0` when the base is live across the branch (delay
  slot + cold block both read the base). Try making the base live longer
  than the state by computing it once before the loop body's other uses, or
  a `volatile`-free reload form like the "Field load CSE'd" entry.
- Check twins: func_00353E30 (matched, same TU, same table) shows the
  member offsets but no shift loop; check the queue for sibling
  CPutMonster_* functions whose scan loop may already be matched.
