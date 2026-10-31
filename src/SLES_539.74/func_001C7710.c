// range: 0x1C7710 0x1C7750
#include "common.h"

M2C_UNK func_001A7060(f32, s32);
extern s32 D_003E06F4;

s32 func_001C7710(char *arg0) {
    f32 val;

    if (*(s32 *)arg0 == 0) {
        val = (f32)*(s32 *)(arg0 + 4);
    } else {
        val = *(float *)(arg0 + 4);
    }
    func_001A7060(val, D_003E06F4);
    return 1;
}
