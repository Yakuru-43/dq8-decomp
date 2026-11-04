// range: 0x20E1A0 0x20E300
// rodata: 0x3C7880 0x3C78B0
#include "common.h"

s32 *func_0020D7E0(void *obj);
s32 func_0020D820(void *obj);
s32 func_0020DB50(void *obj);
s32 *func_0020E300(void *obj, s32 idx);

s32 func_0020E1A0(void *obj, s32 n) {
    s32 *base;
    s32 *record;

    base = func_0020D7E0(obj);
    record = func_0020E300(obj, func_0020D820(obj));
    switch (n) {
    case -11:
    case -10:
    case -9:
    case -8:
    case -7:
    case -6:
    case -5:
    case -4:
    case -1:
        break;
    case -12:
    case -2:
        base[0] = 7;
        record[2] = 0;
        break;
    case -3:
        base[0] = 4;
        break;
    }
    if (n == -1 || (n >= -0x13 && n <= -0xB) || (n >= -0x31 && n <= -0x28) ||
        (n >= -0x3B && n <= -0x32) || (n >= -0x4F && n <= -0x46)) {
        base[0] = 8;
        record[0] = 0;
        if (M2C_FIELD(obj, s32 *, 4) == 6) {
            base[0] = 6;
        }
    }
    if (n < 0) {
        base[1] = func_0020DB50(obj);
        base[3] = M2C_FIELD(obj, s32 *, 0xC);
        base[2] = M2C_FIELD(obj, s32 *, 0x9C4);
    }
    return 1;
}
