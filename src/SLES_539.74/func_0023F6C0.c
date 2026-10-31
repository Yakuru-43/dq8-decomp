// range: 0x23F6C0 0x23F740
#include "common.h"

extern char *D_003E0B24;

s32 func_0023F6C0(char *arg0, s32 arg1) {
    f32 val;
    s32 *ptr;
    char *p;

    if (arg1 != 3) {
        return 0;
    }

    val = *(f32 *)(D_003E0B24 + 0xB0);
    if (*(s32 *)(arg0 + 0) == 3) {
        ptr = *(s32 **)(arg0 + 4);
        *(f32 *)((char *)ptr + 4) = val;
    }

    val = *(f32 *)(D_003E0B24 + 0xB4);
    p = arg0 + 8;
    if (*(s32 *)p == 3) {
        ptr = *(s32 **)(p + 4);
        *(f32 *)((char *)ptr + 4) = val;
    }

    val = *(f32 *)(D_003E0B24 + 0xB8);
    if (*(s32 *)(arg0 + 0x10) == 3) {
        ptr = *(s32 **)(arg0 + 0x14);
        *(f32 *)((char *)ptr + 4) = val;
    }

    return 1;
}
