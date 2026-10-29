# func_0047FAC0 (BATTLE)

Best attempt: `CLASS structural score=67 (56 words differ, 224 vs 180 bytes)`

- Size: 192 B (0x47FAC0–0x47FB80), bin BATTLE, queue line 3.
- Neighbours func_0047FB80 / func_0047FC40 (both 192 B, still `todo`) are
  likely twins — same callees, worth doing together.

## What it does

- `lw v0, 0xB4(a1)`; `beqz v0 → return 1` (plain `beqz`, `daddu s1,$a0` in
  the delay slot — s1 = arg0).
- `addiu a0, v0, 8`; `beql a0,zero → return 1` (branch-likely on the
  computed pointer; `addiu v0,zero,1` in the delay slot).
- Four chained `jal func_00479C50` (the matched list-walker: `arg0 + *(s16
  *)(arg0+2)`), starting from `p+8` where `p = *(a1+0xB4)`.
  After call i, `lwc1 f0, 4(v0)` then the `swc1 f0, 0x30/0x34/0x38(sp)`
  store rides the **next** jal's delay slot: buf[0..2] = float at node+4
  for the first three nodes; the fourth call's result is discarded.
- `addiu s0,$a0,4` sits in the **first** chain jal's delay slot: s0 = p+8+4
  is computed once at entry and kept alive in $s0 across all four calls
  (passed as $a1 to func_0046E090).
- `lw a0,-0x56A0($gp)` → global at 0x3E1BD0 (gp 0x3E7270).
- `jal func_0046E090` with $a0 = that global, $a1 = s0, and its 4 stack
  args at sp+0x30..0x3C: buf[0], buf[1], buf[2] and 1.0f
  (`lui v0,0x3F80` before the call, `sw v0,0x3C(sp)` in the delay slot).
  **The outgoing arg area overlaps buf** — buf is at sp+0x30.
- `jal func_16D5B0(arg0 /*s1*/, v0)` (`daddu a1,$v0` in the delay slot);
  `beql v0,zero → return 1`; `jal func_151A20(v0, &buf /* addiu a1,sp,0x30
  in delay slot */)`; fall through to `return 0`; shared epilogue
  (ld $ra 0x20, lq $s1 0x10, lq $s0 0x0, frame 0x40).

## Best C (attempt 1, score 67)

```c
// range: 0x47FAC0 0x47FB80
#include "common.h"

char *func_00479C50(char *);
s32 func_0046E090(void *, char *, f32, f32, f32, f32);
char *func_16D5B0(s32, s32);
void func_151A20(void *, void *);
extern void *D_003E1BD0;

typedef struct {
    char pad0[0xB4];
    char *fieldB4;
} S_47FAC0;

s32 func_0047FAC0(s32 arg0, S_47FAC0 *arg1) {
    f32 buf[4];
    char *base;
    char *node;
    char *n1, *n2, *n3;
    s32 handle;
    char *obj;

    base = arg1->fieldB4;
    if (base == 0) { return 1; }
    node = base + 8;
    if (node == 0) { return 1; }
    n1 = func_00479C50(node);
    buf[0] = *(f32 *)(n1 + 4);
    n2 = func_00479C50(n1);
    buf[1] = *(f32 *)(n2 + 4);
    n3 = func_00479C50(n2);
    buf[2] = *(f32 *)(n3 + 4);
    func_00479C50(n3);
    buf[3] = 1.0f;
    handle = func_0046E090(D_003E1BD0, node + 4, buf[0], buf[1], buf[2], buf[3]);
    obj = func_16D5B0(arg0, handle);
    if (obj == 0) { return 1; }
    func_151A20(obj, buf);
    return 0;
}
```

## Diff / what went wrong

First real difference is the frame word: mine `addiu $sp,$sp,-0x60`, orig
`-0x40`; mine saves s0–s3 (frame 0x60), orig only s0/s1 (ra at 0x20). From
the call to func_0046E090 onward the whole tail is shifted: mine reloads
buf[i] with `lwc1` through an $s2 buf-pointer and an extra `mtc1` for the
1.0f, while the original has all 6 args already placed (a0, a1=s0, and the
4 stack slots = buf written earlier by the swc1 delay-slot stores).
CLASS structural every time (scores 67/82/82/79).

## Tried (4 attempts, ~18 min)

- Prototype (f32 args) vs no-prototype `s32 func_0046E090();` — both keep
  the oversized frame.
- Separate n1/n2/n3 vs one `n` reassigned — no change (score 82).
- Drop `handle` local, inline `func_0046E090` into the `func_16D5B0` arg.
- One `node` variable with `node = node + 4;` right after the first chain
  call, `buf[3]` removed and `1.0f` passed as the literal — grew the frame
  to 0x70 (score 79).

CW will not keep only {arg0, p+4} in $s registers; it insists on spilling
the node walk / buf pointer. Guess for the original: a typed node struct
(`struct Node { char pad[4]; f32 f; }`) with the walk on a **struct
pointer member of a struct kept in $s0**, so the +4/+8 displacements fold
into the loads instead of into temporaries; and `func_0046E090` is likely
the local-buffer-consuming variant that takes `(void *, void *, f32, f32,
f32, f32)` with the caller letting the outgoing-arg area coincide with the
buf (as in src/BATTLE/func_004614B0.c). MH2 ref not consulted (never
near-miss, always structural).
