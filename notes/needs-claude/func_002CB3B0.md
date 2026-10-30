# needs-claude: func_002CB3B0

CLASS structural score=34 (31 words differ, 172 vs 160 bytes) — best attempt
(the goto form below). Identical score/size for all three shapes tried.

- size: 0xA0 (160 bytes), bin SLES_539.74, `asm/SLES_539.74/game_2C9540.s:2229`
- range: 0x002CB3B0 0x002CB450
- immediate neighbour `func_002CB310` (same wall, see func_002CB310.md; its
  best C is the twin of mine with callee `func_002B09C0` and load `0x412004CC`).

## What it does
Float scorer, returns f32 in $f0:
`func_00359CF0(D_00421AD0, key) == 0` → 8.0f;
flag at raw 0x41000020 != 0 → `2.0f * (f32)func_002B0A30(&D_0042EA80, *(s32*)0x41000000)`;
else `func_0016D5B0(obj, key) == 0` → 10.0f, else `2.0f * *(f32*)0x412004C8`.

## Original block layout (the shape to reproduce)
```
guard:  beql v0,zero,STUB8 ; lui v0,0x4100      <- delay-slot lui SHARED:
flag:   lw   v1,0x20(v0)                          v0 is also base for +0x20/+0x0 loads
        beql v1,zero,CHK          ; (no delay use of v1)
B0A30:  lw   a1,0x0(v0) ; lui a0,%hi(D_0042EA80) ; jal func_002B0A30 ; ...
        mtc1 v0,f0 ; nop ; cvt.s.w f1,f0          <- falls THROUGH into MUL
MUL:    lui v0,0x4000 ; mtc1 f0 ; b EPI ; mul.s f0,f0,f1   <- one shared mul block
STUB8:  mtc1 f0 (v0=0x41000000) ; b RET1 (ld ra, skip mul)
CHK:    jal func_0016D5B0(a0=s1,a1=s0) ; beql v0,zero,STUB10 ; lui v0,0x4120
        b MUL (BACKWARD) ; lwc1 f1,0x4C8(v0)      <- 0x4120 lui SHARED as base 10.0f
STUB10: mtc1 f0 ; EPI: ld ra,0x20(sp)
RET1:   lq s1 ; lq s0 ; jr ra ; addiu sp,0x30
```
Key points: (1) ONE mul block, B0A30 arm falls into it, 16D5B0 arm jumps back to
it with `lwc1` in the `b`'s delay slot; (2) the 8.0f/10.0f constants double as
address bases 0x41000000/0x41200000 (lui in the branch delay slot, reused).

## Best C (attempt 3 of 3)
```c
// range: 0x002CB3B0 0x002CB450
#include "common.h"

extern char D_00421AD0[] __attribute__((section(".data")));
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));

u32 func_00359CF0(char *, s32);
s32 func_002B0A30(M2C_UNK *, s32);
s32 func_0016D5B0(void *, s32);

f32 func_002CB3B0(void *obj, s32 key) {
    f32 scale;
    u32 work;

    work = func_00359CF0(D_00421AD0, key);
    if (work == 0) {
        return 8.0f;
    }
    if (*(s32 *)0x41000020 != 0) {
        scale = (f32)func_002B0A30(&D_0042EA80, *(s32 *)0x41000000);
scaled:
        return 2.0f * scale;
    }
    if (func_0016D5B0(obj, key) == 0) {
        return 10.0f;
    }
    scale = *(f32 *)0x412004C8;
    goto scaled;
}
```

## Diff (first real difference +0x24; whole tail diverges)
First word of divergence: guard `beql` target mine +0x4C vs orig +0x3C (mine is
12 bytes longer). Mine: duplicates `lui v0,0x4100` after the beql (+02C, orig
reuses the delay-slot one), tests the flag with `bnel` (orig `beql` forward to
the cold CHK block), and places the B0A30 block at the BOTTOM (+080, with
`cvt.s.w` in a `b -0xC` delay slot) instead of between guard and mul; mine has
chain of `b`s around the single mul block instead of fall-through + one back b.
Full `--show` tail reproducible with:
`tools/try_match.py src/... (see best.c copy) func_002CB3B0 0x002CB3B0 --show -- -O3`

## Tried (all CLASS structural score=34, 172 vs 160)
1. if/else on `*(s32*)0x41000020 != 0` first, `return 2.0f*scale` tail.
2. Twin order `== 0` first (the func_002CB310 best-C shape).
3. goto-shared tail, mul written once between the two arms (above).
MH2 entry tried: index line 207 "One block reached from two cases or paths:
a goto; MWCC doesn't merge tails (Switches)" — the goto form still re-ordered
and did not fold the extra lui.
Not tried: permute.py (31 words differ = not close; finisher is for near misses).

## Notes for Claude
- Same score/size as the twin func_002CB310: both sessions, three spellings
  each → this family (float scorer with raw-addr flag + shared 2.0f*x tail)
  seems to defeat normal if/else/goto forms at -O3. Maybe needs `-O4,p`, a
  `// flags:` line, or a float local scheduled differently (idioms.md
  "Float temporaries swapped"). The double-duty lui (float const = addr base)
  suggests the original had the 8.0f/10.0f returns and the loads fed from the
  same constant-expression somehow (e.g. a named `const f32` also taken
  address-of? or MWCC CSE of `(u32)8.0f`).
- func_002CB310 sibling uses callees func_002B09C0/0x412004CC; mine
  func_002B0A30/0x412004C8 — likely the same source function class with a
  different pool object; solving one probably solves both.
