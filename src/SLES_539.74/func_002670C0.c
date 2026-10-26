// range: 0x2670C0 0x267100
#include "common.h"

extern f32 D_003DF3E8;
extern s32 D_003E04AC;

extern void *func_0016AF30();

void func_002670C0(void *arg0) {
    char *obj;
    f32 scale;

    obj = func_0016AF30(arg0, *(s32 *)((char *)arg0 + 0x44B4));
    scale = D_003DF3E8;
    *(f32 *)(obj + 0x244) = scale;
    *(f32 *)(obj + 0x24C) = scale;
    *(f32 *)(obj + 0x248) = 3.0f;
    D_003E04AC = 0;
}
