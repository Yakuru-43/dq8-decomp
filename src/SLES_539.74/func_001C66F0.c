// range: 0x1C66F0 0x1C6770
#include "common.h"

M2C_UNK func_001A61F0(s32, s32, s32, f32);
extern s32 D_003E06F4;

s32 func_001C66F0(char *arg0) {
    s32 a1;
    s32 a2;
    f32 f12;
    char *temp_v1;

    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(float *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    temp_v1 = arg0 + 8;
    if (*(s32 *)(arg0 + 8) == 0) {
        f12 = (f32)*(s32 *)(temp_v1 + 4);
    } else {
        f12 = *(float *)(temp_v1 + 4);
    }
    if (*(s32 *)(arg0 + 0x10) == 1) {
        a2 = (s32)*(float *)(arg0 + 0x14);
    } else {
        a2 = *(s32 *)(arg0 + 0x14);
    }
    func_001A61F0(D_003E06F4, a1, a2, f12);
    return 1;
}
