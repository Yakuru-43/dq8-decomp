# func_002FFAD0 — needs-claude

- Queue: `build/queue.tsv`, binary `SLES_539.74`, addr `0x002FFAD0`, size 496 B
  (`0x2FFAD0`–`0x2FFCC0`). Asm in `asm/SLES_539.74/game_2FFAB0.s` lines 25–154.
- What it does: copies 4 s32 from `a1` to a stack struct (`sp+0x90..0x9C`,
  via `lwc1`/`swc1`), null-checks `a0` and `a2` (early returns), then:
  `func_002E2880()`, `func_0013F6C0(obj, 6)`, `func_0013EB30(obj, tag)`,
  `func_0013ECD0(obj, 0x80, 0x80, 0x80, 0x80)`; converts the 4 ints to float
  (`cvt.s.w`), clamps: `if (2.0f + x < 0.0f) { z = z + (2.0f + x); x = 2.0f; }`
  (else-path stores `2.0f` to the x slot, `fz + (2.0f + fx)` to the z slot,
  via `swc1` after the branch); computes 6 ints before the first `jal`:
  `y0=(s32)(2.0f+y)`, `x0=(s32)(2.0f+x)`, `dy1=(s32)(w-4.0f)`,
  `dy2=(s32)(w-4.0f-1.0f)`, `dx2=(s32)(z-4.0f-1.0f)`, `dx1=(s32)(z-4.0f)`;
  then `func_0013EBF0(obj,x0,y0)`, `func_0013EF90(obj,x0,y0,0)`,
  `func_0013EBF0(obj,x0+dx1,y0+dy1)`, `func_0013EF90(obj,x0+dx2,y0+dy2,0)`,
  `func_0013F450(obj)`. Looks like the quad-texture draw of `func_002FF6E0`.
- Slot map (original): `sp+0x80` = float(y), `0x84` = float(x), `0x88` = float(w),
  `0x8C` = float(z); loads after the merge go through base `addiu $v1, $sp, 0x80`
  (four `lwc1` $v1,0/4/8/0xC); the 0x84 store goes through `addiu $a0, $sp, 0x84`.
  Saved regs: `s5`=obj, `s0`=tag (then reused for dy1), `s4`=y0, `s3`=x0,
  `s2`=dy2, `s1`=dx2, `s6`=dx1; `ra` at `sp+0x70`; frame `0xA0`.

## The blocker
Every plain-C shape I tried makes CodeWarrior keep the two never-modified
floats (y, w) in callee-saved `$f20/$f21` across the call group, so it only
saves `s0..s2` (frame `0x60`) and rotates the six `cvt.w.s`/`mfc1` int
conversions *between* the `jal`s instead of computing all six before the first
`func_0013EBF0`. The original never uses `$f20+`: all four floats live in the
stack slots `0x80..0x8C` from their def site (stores `swc1` at +0x80/+0x84/+0x88
around the `bc1t`, +0x8C before it) until the reload after the merge. Diff
stays ~106/120 lines because the prologue/frame differs from +0x00.

## Best C (uncommitted; slot mapping in comments)
Plain locals and a `f32 q[4]` array both scalarize to `f20/f21`; the struct
variant below differs only in which floats it keeps in registers. Try: forcing
memory residency (volatile? permuter over statement order? different call
argument order that shortens the int live ranges before the calls?).

```c
// range: 0x2FFAD0 0x2FFCC0
#include "common.h"

void func_002E2880(void);
void func_0013F6C0(void *, s32);
void func_0013EB30(void *, void *);
void func_0013ECD0(void *, s32, s32, s32, s32);
void func_0013EBF0(void *, s32, s32);
void func_0013EF90(void *, s32, s32, s32);
void func_0013F450(void *);

struct Int4 { s32 x; s32 y; s32 z; s32 w; };

void func_002FFAD0(void *obj, struct Int4 *src, void *tag) {
    struct Int4 t;
    f32 q[4];              /* q[0]=y@0x80, q[1]=x@0x84, q[2]=w@0x88, q[3]=z@0x8C */
    s32 y0; s32 x0; s32 dy1; s32 dy2; s32 dx2; s32 dx1;

    t = *src;
    if (obj == 0) { return; }
    if (tag == 0) { return; }
    func_002E2880();
    func_0013F6C0(obj, 6);
    func_0013EB30(obj, tag);
    func_0013ECD0(obj, 0x80, 0x80, 0x80, 0x80);
    q[1] = (f32)t.x;
    q[0] = (f32)t.y;
    q[3] = (f32)t.z;
    q[2] = (f32)t.w;
    if (2.0f + q[1] < 0.0f) {
        q[3] = q[3] + (2.0f + q[1]);
        q[1] = 2.0f;
    }
    y0 = (s32)(2.0f + q[0]);
    x0 = (s32)(2.0f + q[1]);
    dy1 = (s32)(q[2] - 4.0f);
    dy2 = (s32)(q[2] - 4.0f - 1.0f);
    dx2 = (s32)(q[3] - 4.0f - 1.0f);
    dx1 = (s32)(q[3] - 4.0f);
    func_0013EBF0(obj, x0, y0);
    func_0013EF90(obj, x0, y0, 0);
    func_0013EBF0(obj, x0 + dx1, y0 + dy1);
    func_0013EF90(obj, x0 + dx2, y0 + dy2, 0);
    func_0013F450(obj);
}
```

## Tried (5 attempts, ~25 min)
1. Four plain `f32` locals, int conversions + calls in asm order → allocator
   used `f20/f21`, frame `0x60`, calls interleaved with cvts. All diff from +0.
2. Same but floats via `struct Float4` local → still scalarized, same plan.
3. `f32 q[4]` array with matching slot order → still scalarized, same plan.
   (Diff excerpt: mine `addiu $sp,$sp,-0x60; sd $ra,0x40($sp); sq $s2/$s1;
   swc1 $f21,$f20...` vs orig `addiu $sp,$sp,-0xA0; sd $ra,0x70($sp);
   sq $s6..$s0`.)
