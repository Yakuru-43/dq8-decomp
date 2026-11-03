// range: 0x1758B0 0x175B20
// rodata: 0x3C2B50 0x3C2B80
#include "common.h"

extern u8 D_00405364 __attribute__((section(".data")));
extern s32 D_0040536C[] __attribute__((section(".data")));
extern s32 D_00405378[] __attribute__((section(".data")));
extern u8 D_0040537E[] __attribute__((section(".data")));
extern u8 D_0040537F[] __attribute__((section(".data")));
extern s32 D_00405380[] __attribute__((section(".data")));
extern s32 D_00405384[] __attribute__((section(".data")));
extern s32 D_00405388[] __attribute__((section(".data")));
extern u8 D_00408690 __attribute__((section(".data")));
extern s32 D_004086C0[] __attribute__((section(".data")));

struct Entry {
    void *f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 fD;
    s32 pad10;
    s32 f14;
};

s32 func_001758B0(s32 arg0, struct Entry *arg1) {
    s32 idx;
    s32 *f4;
    s32 *f8;

    arg1->fC = 0;
    arg1->fD = 0;
    f4 = &arg1->f4;
    f8 = &arg1->f8;
    if (D_00405364 != 0) {
        if (arg0 < 0 || arg0 >= 0x10) {
            return 0;
        }
        arg1->f4 = D_00405384[arg0 * 9];
        arg1->f8 = D_00405388[arg0 * 9];
        arg1->fC = D_0040537E[arg0 * 0x24];
        arg1->fD = D_0040537F[arg0 * 0x24];
    } else {
        switch (arg0) {
        case 0:
            *f4 = 0;
            *f8 = 0;
            arg1->fC = 1;
            break;
        case 11:
            *f4 = 3;
            *f8 = 3;
            arg1->fC = 1;
            break;
        case 1:
            *f4 = 0xC;
            *f8 = -1;
            break;
        case 2:
            *f4 = 1;
            *f8 = 1;
            break;
        case 3:
            *f4 = 6;
            *f8 = -1;
            break;
        case 4:
            *f4 = 0xB;
            *f8 = 2;
            break;
        case 5:
            *f4 = 0xA;
            *f8 = -1;
            break;
        case 6:
            *f4 = 9;
            *f8 = -1;
            break;
        case 7:
            *f4 = 5;
            *f8 = -1;
            break;
        case 8:
            *f4 = 8;
            *f8 = 0xD;
            arg1->fC = 1;
            break;
        case 9:
            *f4 = 4;
            *f8 = -1;
            break;
        case 10:
            *f4 = 7;
            *f8 = -1;
            arg1->fD = 1;
            arg1->f14 = 0;
            break;
        default:
            return 0;
        }
    }
    arg1->f14 = D_0040536C[arg0 * 9];
    idx = D_00405378[arg0 * 9];
    if (idx >= 0) {
        arg0 = idx;
    }
    if (D_00405380[arg0 * 9] > 0) {
        arg1->f0 = &D_004086C0[arg0 * 0xA];
    } else {
        arg1->f0 = &D_00408690;
    }
    return 1;
}
