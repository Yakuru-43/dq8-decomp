// range: 0x1575A0 0x157650
#include "common.h"

extern void func_0013D290(char *);

void func_001575A0(char *arg0) {
    s32 i;
    char *base;
    s32 f4300 = 0x43000000;
    s32 f437f = 0x437F0000;
    s32 fbf80 = 0xBF800000;

    *(s32 *)(arg0 + 4) = 0;
    *(s128 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x1C) = f4300;
    func_0013D290(arg0 + 0x20);
    func_0013D290(arg0 + 0x60);
    *(s128 *)(arg0 + 0xA0) = 0;
    *(s32 *)(arg0 + 0xCC) = f4300;
    *(s32 *)(arg0 + 0xC8) = f4300;
    i = 0;
    *(s32 *)(arg0 + 0xC4) = f4300;
    *(s32 *)(arg0 + 0xC0) = f4300;
    *(s128 *)(arg0 + 0xD0) = *(s128 *)(arg0 + 0xC0);
    *(s32 *)(arg0 + 0xBC) = f437f;
    *(s32 *)(arg0 + 0xB8) = f437f;
    *(s32 *)(arg0 + 0xB4) = f437f;
    *(s32 *)(arg0 + 0xB0) = f437f;
    do {
        base = arg0 + i * 0x30;
        i++;
        *(s32 *)(base + 0x100) = fbf80;
        *(s128 *)(base + 0xF0) = 0;
        *(s128 *)(base + 0xE0) = 0;
    } while (i < 4);
}
