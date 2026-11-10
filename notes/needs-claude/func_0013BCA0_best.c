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
