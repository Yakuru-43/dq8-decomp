// range: 0x469C00 0x469F00
// flags: -flag divbyzerocheck
#include "common.h"

extern char D_0047FE60[] __attribute__((section(".data")));
extern s32 D_0047FE64 __attribute__((section(".data")));
extern s32 D_0047FE84 __attribute__((section(".data")));
extern s32 D_0047FE94 __attribute__((section(".data")));
extern s32 D_0047FEA4 __attribute__((section(".data")));
extern s32 D_0047FEC4 __attribute__((section(".data")));
extern s32 D_0047FEE4 __attribute__((section(".data")));
extern s32 D_0047FEF4 __attribute__((section(".data")));
extern s32 D_0047FF04 __attribute__((section(".data")));
extern s32 D_0047FF24 __attribute__((section(".data")));
extern u8 *D_003E17C8 __attribute__((section(".sdata")));

s32 func_00469C00(void) {
    u32 buf[25];
    u8 *p;
    u32 n;
    s32 count;
    s32 i;
    s32 j;
    s32 idx;
    s32 row;
    s32 col;

    count = 0;
    p = (u8 *)buf;
    n = 100;
    if (p != 0) {
        do {
            *p = 0;
            n = n - 1;
            p = p + 1;
        } while (n != 0);
    }

    for (i = 0; i < 5; i++) {
        idx = i * 5;
        if (*(s32 *)(D_0047FE60 + idx * 8 + 4) != 0 &&
            *(s32 *)(D_0047FE60 + idx * 8 + 0xC) != 0 &&
            *(s32 *)(D_0047FE60 + idx * 8 + 0x14) != 0 &&
            *(s32 *)(D_0047FE60 + idx * 8 + 0x1C) != 0 &&
            *(s32 *)(D_0047FE60 + idx * 8 + 0x24) != 0) {
            count = count + 1;
            for (j = 0; j < 5; j++) {
                buf[idx + j] = 1;
            }
        }
    }

    for (j = 0; j < 5; j++) {
        if (*(s32 *)(D_0047FE60 + j * 8 + 4) != 0 &&
            *(s32 *)(D_0047FE60 + j * 8 + 0x2C) != 0 &&
            *(s32 *)(D_0047FE60 + j * 8 + 0x54) != 0 &&
            *(s32 *)(D_0047FE60 + j * 8 + 0x7C) != 0 &&
            *(s32 *)(D_0047FE60 + j * 8 + 0xA4) != 0) {
            count = count + 1;
            for (i = 0; i < 5; i++) {
                buf[i * 5 + j] = 1;
            }
        }
    }

    if (D_0047FE64 != 0 && D_0047FE94 != 0 && D_0047FEC4 != 0 &&
        D_0047FEF4 != 0 && D_0047FF24 != 0) {
        count = count + 1;
        for (i = 0; i < 5; i++) {
            buf[i * 6] = 1;
        }
    }

    if (D_0047FE84 != 0 && D_0047FEA4 != 0 && D_0047FEC4 != 0 &&
        D_0047FEE4 != 0 && D_0047FF04 != 0) {
        count = count + 1;
        for (i = 0; i < 5; i++) {
            buf[i * 4 + 4] = 1;
        }
    }

    if (count != 0) {
        for (i = 0; i < 25; i++) {
            row = i / 5;
            col = i % 5;
            if (*(s32 *)(D_0047FE60 + row * 40 + col * 8 + 4) != 0) {
                if (buf[i] != 0) {
                    D_003E17C8[i + 0x100] = 6;
                } else {
                    D_003E17C8[i + 0x100] = 5;
                }
            }
        }
    }

    return count;
}
