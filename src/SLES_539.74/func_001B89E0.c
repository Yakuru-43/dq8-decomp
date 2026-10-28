// range: 0x1B89E0 0x1B8A70
#include "common.h"

extern char *D_003E0664;
extern char *func_0016AF30(char *, s32);

s32 func_001B89E0(char *arg0) {
    f32 f22, f21, f20;
    char *temp_v0;
    char *v1;

    if (*(s32 *)(arg0 + 0) == 0) {
        f22 = (f32)(*(s32 *)(arg0 + 4));
    } else {
        f22 = *(f32 *)(arg0 + 4);
    }

    v1 = arg0 + 8;
    if (*(s32 *)(arg0 + 8) == 0) {
        f21 = (f32)(*(s32 *)(v1 + 4));
    } else {
        f21 = *(f32 *)(v1 + 4);
    }

    if (*(s32 *)(arg0 + 0x10) == 0) {
        f20 = (f32)(*(s32 *)(arg0 + 0x14));
    } else {
        f20 = *(f32 *)(arg0 + 0x14);
    }

    temp_v0 = func_0016AF30(D_003E0664, *(s32 *)(D_003E0664 + 0x44B4));
    *(f32 *)(temp_v0 + 0x200) = f22;
    *(f32 *)(temp_v0 + 0x204) = f21;
    *(f32 *)(temp_v0 + 0x208) = f20;
    *(s32 *)(temp_v0 + 0x20C) = 0;
    return 1;
}
