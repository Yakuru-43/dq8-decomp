// range: 0x100EE0 0x100F80
#include "common.h"

/* Read a 1..4 byte big-endian value at p, length from the low bits of
 * byte 0; returns the pointer after the value. Unsigned twin of
 * func_00100F80. */
u8 *func_00100EE0(u8 *p, u32 *out) {
    u32 b = p[0];
    u32 b1;
    u32 b2;

    if ((b & 1) == 0) {
        *out = b >> 1;
        return p + 1;
    }
    b1 = p[1];
    if ((b & 2) == 0) {
        *out = ((b >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = p[2];
    if ((b & 4) == 0) {
        *out = ((b >> 3) << 16) | (b1 << 8) | b2;
        return p + 3;
    }
    *out = ((b >> 3) << 24) | (b1 << 16) | (b2 << 8) | p[3];
    return p + 4;
}
