// range: 0x460F70 0x461040
#include "common.h"

s32 func_0045F640(s32);
s32 func_202590(void);
s32 func_00464FA0(void);
extern s32 D_00415EA4 __attribute__((section(".data")));

s32 func_00460F70(s32 arg0) {
    s32 best;
    s32 i;
    s16 val;
    s32 price;
    s32 stamp;

    best = 99999;
    i = 0;
    while (0 < (val = *(s16 *)((char *)D_00415EA4 + i * 2 + 0xC))) {
        price = func_0045F640(val);
        if (price < best) {
            best = price;
        }
        i++;
    }
    stamp = func_202590();
    if (arg0 != 0) {
        if (stamp - func_00464FA0() < best) {
            return 1;
        }
    } else {
        if (func_202590() < best) {
            return 1;
        }
    }
    return 0;
}
