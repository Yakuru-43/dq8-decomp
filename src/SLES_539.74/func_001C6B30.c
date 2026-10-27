// range: 0x1C6B30 0x1C6B80
#include "common.h"

M2C_UNK func_001A6AC0(f32, s32, s32);
extern s32 D_003E06F4;

s32 func_001C6B30(char *arg0) {
    f32 a0;
    s32 a1;
    s64 ra;

    if (*(s32 *)arg0 == 0) {
        a0 = (f32)*(s32 *)(arg0 + 4);
    } else {
        a0 = *(f32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }
    func_001A6AC0(a0, D_003E06F4, a1);
    return 1;
}
