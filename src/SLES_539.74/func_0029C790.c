// range: 0x29C790 0x29C7E0
#include "common.h"

extern s32 func_0029C5D0(s32);

u32 func_0029C790(u32 arg0) {
    u32 cursor;

    cursor = arg0;
    do {
        func_0029C5D0(cursor);
        cursor += 0x2C;
    } while (cursor < arg0 + 0x1B8);
    return arg0;
}
