// range: 0x00141830 0x001418B0
#include "common.h"

extern void func_001414D0(void *d, void *a, s32 *r, void *b,
                          s32 w __attribute__((param_reg(8))),
                          s32 h __attribute__((param_reg(9))),
                          s32 f __attribute__((param_reg(10))));

/* Halve the scale of two groups: divide the four quads at src by 16 on the
 * stack, undo the 16x of the hot scalars, and build the packet. */
void func_00141830(void *d, void *a, s32 *src, void *b,
                   s32 w __attribute__((param_reg(8))),
                   s32 h __attribute__((param_reg(9))),
                   s32 f __attribute__((param_reg(10)))) {
    s32 q[4];

    q[0] = src[0];
    q[1] = src[1];
    q[2] = src[2];
    q[3] = src[3];
    q[0] >>= 4;
    q[1] >>= 4;
    q[3] >>= 4;
    q[2] >>= 4;
    func_001414D0(d, a, q, b, w >> 4, h >> 4, f);
}
