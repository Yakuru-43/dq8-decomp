// range: 0x1C6EA0 0x1C6EF0
#include "common.h"

M2C_UNK func_001A7290(s32, s32, f32);
extern s32 D_003E06F4;

s32 func_001C6EA0(char *arg0) {
    f32 fval;
    s32 ival;

    if (*(s32 *)arg0 == 0) {
        fval = (f32)*(s32 *)(arg0 + 4);
    } else {
        fval = *(f32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        ival = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        ival = *(s32 *)(arg0 + 0xC);
    }
    func_001A7290(D_003E06F4, ival, fval);
    return 1;
}
