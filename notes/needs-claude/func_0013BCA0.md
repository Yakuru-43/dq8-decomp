# needs-claude: func_0013BCA0

CLASS structural score=12 (12 words differ, 124 vs 124 bytes)
Best attempt's only diff: register allocation + one rematerialized load (see below).

- asm: `asm/SLES_539.74/game_13BCA0.s`, range 0x13BCA0–0x13BD20 (128 B, 124 B code)
- What it does: normalizes an angle to (-π, π]. Fast path returns `angle` when
  `-π < angle < π`; otherwise `angle -= 2π * (f32)(s32)(angle / 2π)` (emitted as
  mtc1/adda/div/cvt.w.s/cvt.s.w/msub), then the two fixups
  `if (!(angle <= π)) angle -= 2π;` `if (angle < -π) angle += 2π;`.
  Globals are D_003DF3D0=π, D_003DF3D4=-π, D_003DF3D8=2π, D_003DF3DC=-π,
  D_003DF3E0=2π (asm/SLES_539.74/data/ctors.data.s:3082).
  Callers (e.g. game_1F3470.s .L001F3A9C) do `field * π / 180.0f` then call this
  — a turn→radians normalize. Sibling `func_0013BD20` (matched, src/SLES_539.74/)
  is the same fixup shape with plain args.

- Best C (src/SLES_539.74/func_0013BCA0.c, not committed):

```c
// range: 0x13BCA0 0x13BD20
#include "common.h"

extern f32 D_003DF3D0;   /* 3.141592741f */
extern f32 D_003DF3D4;   /* -3.141592741f */
extern f32 D_003DF3D8;   /* 6.283185482f */
extern f32 D_003DF3DC;   /* -3.141592741f */
extern f32 D_003DF3E0;   /* 6.283185482f */

f32 func_0013BCA0(f32 angle) {
    f32 upper = D_003DF3D0;

    if (angle < upper && angle > D_003DF3D4) {
        return angle;
    }
    angle -= D_003DF3D8 * (f32)(s32)(angle / D_003DF3D8);
    if (!(angle <= upper)) {
        angle -= D_003DF3D8;
    }
    if (angle < D_003DF3DC) {
        angle += D_003DF3E0;
    }
    return angle;
}
```

- The diff (try_match --show, left=orig right=mine): every instruction matches in
  order EXCEPT the original loads D_003DF3D0 ONCE at +000 into `$f2` and still has
  it live at +048 (`c.le.s $f12, $f2`), while mine loads π into `$f0` at +000,
  clobbers f0 at +010 with -π, and RELOADS D_003DF3D0 at +030 (where the original
  has the `nop` delay slot after `mtc1`); then f1/f2 and f0/f2 swap through the
  body. Original registers: π→$f2 (live +000..+048), 2π→$f1 (live +028..+054,
  across the +04C branch), temp chain (mtc1/adda/div/cvt/cvt/msub)→$f0.

- Tried: (1) plain `D_003DF3D0` written three times — CW reloads at +030;
  (2) `f32 upper = D_003DF3D0;` local used in both comparisons (above) — CW still
  splits into two loads; (3) nested `if (angle < upper) { if (angle > ...) }` —
  worse (132 B, duplicated epilogue, score=31); `&&` restored. `(f32)(s32)(...)`
  reproduces the dead `mtc1 $zero`+`adda.s` exactly — do not fight it.
- tools/permute.py blocked: permuter needs `cpp`, not on this host
  (same as the func_0013B9C0 note). target.s/target.o/compile.sh set up under
  build/permute/func_0013BCA0/ for a host that has cpp.
- Question for Claude: which C shape stops CW from rematerializing the
  D_003DF3D0 load into the body (keeps one lwc1 at +000 feeding both FPCs)?
