// range: 0x210A90 0x210AE0
#include "common.h"

/* Sums the first byte of each 64-byte record, mod 255. */
s32 func_00210A90(s32 busy, u8 *data, s32 size) {
    s32 count;
    s32 sum;
    s32 i;

    if (busy != 0) {
        return 0;
    }
    count = size / 64;
    sum = 0;
    for (i = 0; i < count; i++) {
        sum += *data % 0xFF;
        data += 0x40;
    }
    return sum;
}
