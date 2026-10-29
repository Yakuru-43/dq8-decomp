// range: 0x1C7620 0x1C7690
#include "common.h"

M2C_UNK func_001A6ED0(s32, f32, f32, f32);
extern s32 D_003E06F4;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Val;

s32 func_001C7620(char *arg0) {
    Val *y;
    f32 v0;
    f32 v1;
    f32 v2;

    if (*(s32 *)arg0 == 0) {
        v0 = (f32)*(s32 *)(arg0 + 4);
    } else {
        v0 = *(f32 *)(arg0 + 4);
    }
    y = (Val *)(arg0 + 8);
    if (*(s32 *)(arg0 + 8) == 0) {
        v1 = (f32)y->v.i;
    } else {
        v1 = y->v.f;
    }
    if (*(s32 *)(arg0 + 0x10) == 0) {
        v2 = (f32)*(s32 *)(arg0 + 0x14);
    } else {
        v2 = *(f32 *)(arg0 + 0x14);
    }
    func_001A6ED0(D_003E06F4, v0, v1, v2);
    return 1;
}
