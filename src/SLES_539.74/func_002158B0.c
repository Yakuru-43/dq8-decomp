// range: 0x2158B0 0x2158FC
#include "common.h"

extern void func_00131188(char *, s32, s32);

char *func_002158B0(char *p) {
    func_00131188(p, 0, 0x88);
    *(s32 *)(p + 0x30) = 8;
    *(char **)(p + 0x2C) = p + 0x40;
    *(s32 *)(p + 0x3C) = 8;
    *(char **)(p + 0x38) = p + 0x60;
    return p;
}
