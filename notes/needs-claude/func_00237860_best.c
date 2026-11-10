// best C for func_00237860 (attempt 3, CLASS structural score=56, 304 vs 332 B)
// range: 0x237860 0x2379B0
#include "common.h"

extern u64 func_00139848(u64, u64);
extern u64 func_00139DC8(u64, u64);

s32 func_00237860(void *arg0, u64 arg1, char *arg2) {
    s16 raw;
    u16 mode;
    u32 base;
    u32 upper;
    char *cursor;
    char *lo;
    char *hi;
    u32 digit;
    char tmp;

    if (arg1 == 0) {
        *arg2 = '0';
        return 1;
    }
    raw = M2C_FIELD(arg0, s16 *, 0x38);
    mode = (u16)raw & 0x4A;
    if (mode == 8) {
        base = 16;
    } else if (mode == 0x40) {
        base = 8;
    } else {
        base = 10;
    }
    upper = (raw & 0x4000) != 0;
    cursor = arg2;
    while (arg1 != 0) {
        digit = func_00139DC8(arg1, base);
        if (digit < 10) {
            *cursor = (char)(digit + '0');
        } else if (upper == 0) {
            *cursor = (char)(digit + ('a' - 10));
        } else {
            *cursor = (char)(digit + ('A' - 10));
        }
        cursor = cursor + 1;
        arg1 = func_00139848(arg1, base);
    }
    hi = cursor;
    lo = arg2;
    if (cursor != arg2) {
        hi = cursor - 1;
        while (lo < hi) {
            tmp = *lo;
            *lo = *hi;
            *hi = tmp;
            lo = lo + 1;
            hi = hi - 1;
        }
    }
    return cursor - arg2;
}
