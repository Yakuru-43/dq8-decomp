// range: 0x1C2A10 0x1C2A50
#include "common.h"

M2C_UNK func_0020B7B0(f32, s32);
extern s32 D_003E0664;

s32 func_001C2A10(char *arg0) {
    f32 val;

    if (*(s32 *)arg0 == 0) {
        val = (f32)*(s32 *)(arg0 + 4);
    } else {
        val = *(f32 *)(arg0 + 4);
    }
    func_0020B7B0(val, D_003E0664);
    return 1;
}
