// range: 0x13E200 0x13E290
#include "common.h"

/* Pick a placement mode and set the position fields (0x120/0x124) from
 * the extent fields (0x128/0x12C) and the size fields (0x130/0x134). */
void func_0013E200(void *o, s32 mode) {
    M2C_FIELD(o, s32 *, 0x11C) = mode;
    if (M2C_FIELD(o, s32 *, 0x11C) == 1) {
        M2C_FIELD(o, s32 *, 0x124) = 0;
        M2C_FIELD(o, s32 *, 0x120) = 0;
    } else if (M2C_FIELD(o, s32 *, 0x11C) == 2) {
        M2C_FIELD(o, s32 *, 0x120) = M2C_FIELD(o, s32 *, 0x128);
        M2C_FIELD(o, s32 *, 0x124) = M2C_FIELD(o, s32 *, 0x12C);
    } else {
        M2C_FIELD(o, s32 *, 0x120) =
            M2C_FIELD(o, s32 *, 0x128) - M2C_FIELD(o, s32 *, 0x130) / 2;
        M2C_FIELD(o, s32 *, 0x124) =
            M2C_FIELD(o, s32 *, 0x12C) - M2C_FIELD(o, s32 *, 0x134) / 2;
    }
}
