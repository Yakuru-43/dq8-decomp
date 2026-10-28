// range: 0x1C76D0 0x1C7710
#include "common.h"

M2C_UNK func_001A6FE0(f32, s32);
extern s32 D_003E06F4;

s32 func_001C76D0(char *arg0) {
    f32 val;

    if (*(s32 *)arg0 == 0) {
        val = (f32)*(s32 *)(arg0 + 4);
    } else {
        val = *(f32 *)(arg0 + 4);
    }
    func_001A6FE0(val, D_003E06F4);
    return 1;
}
