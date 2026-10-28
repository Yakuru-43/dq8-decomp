// range: 0x19AD70 0x19AE20
#include "common.h"

s32 func_0019AD70(char *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0x10);
    if (temp_v0 == 0) {
        return 1;
    }

    if (temp_v0 <= 0) {
        temp_f2 = *(f32 *)(arg0 + 0x18);
        temp_f1 = *(f32 *)(arg0 + 0xC) + temp_f2;
        *(f32 *)(arg0 + 0xC) = temp_f1;
        if (temp_f1 >= 128.0f) {
            *(f32 *)(arg0 + 0xC) = 128.0f;
            *(s32 *)(arg0 + 0x14) = 1;
        }
    } else {
        temp_f2 = *(f32 *)(arg0 + 0x18);
        temp_f1 = *(f32 *)(arg0 + 0xC) - temp_f2;
        *(f32 *)(arg0 + 0xC) = temp_f1;
        if (temp_f1 <= 0.0f) {
            *(f32 *)(arg0 + 0xC) = 0.0f;
            *(s32 *)(arg0 + 0x10) = 0;
            *(s32 *)(arg0 + 0x14) = 1;
        }
    }

    if (*(s32 *)(arg0 + 0x14) != 0) {
        if (*(s32 *)(arg0 + 0x20) != 0) {
            if (*(s32 *)(arg0 + 0x1C) == 1) {
                *(f32 *)(arg0 + 0xC) = 0.0f;
            }
        }
    }

    return *(s32 *)(arg0 + 0x14);
}
