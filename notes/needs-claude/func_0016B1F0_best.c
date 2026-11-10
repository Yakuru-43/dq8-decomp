// range: 0x16B1F0 0x16B2E0  (NOT matched — best of 3 tries, byte-identical siblings)
#include "common.h"

void func_0016B1F0(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *p;

    switch (arg1) {
    case 1:
        if ((arg2 >= 0) && (arg2 < M2C_FIELD(arg0, s32 *, 0x550))) {
            p = arg0 + (arg2 * 0x40) + 0x554;
        } else {
            p = NULL;
        }
        break;
    case 2:
        if ((arg2 >= 0) && (arg2 < M2C_FIELD(arg0, s32 *, 0x3A44))) {
            p = arg0 + (arg2 * 0x3C) + 0x3A48;
        } else {
            p = NULL;
        }
        break;
    case 3:
        if ((arg2 >= 0) && (arg2 < M2C_FIELD(arg0, s32 *, 0x3860))) {
            p = arg0 + (arg2 * 0x3C) + 0x3864;
        } else {
            p = NULL;
        }
        break;
    default:
        p = NULL;
        break;
    }
    if (p != NULL) {
        M2C_FIELD(p, s32 *, 4) = arg3;
    }
}
