// range: 0x00141750 0x00141830
#include "common.h"

extern void func_00141020(void *obj, void *arg1, u32 *hi, void *arg3,
                          u32 *lo __attribute__((param_reg(8))));

/* Copy two groups of four quads to the stack, scale each by 16 in place,
 * then hand both groups to the packet builder. */
void func_00141750(void *obj, void *arg1, u32 *src, void *arg3,
                   u32 *hot __attribute__((param_reg(8)))) {
    u32 hi[4];
    u32 lo[4];

    hi[0] = src[0];
    hi[1] = src[1];
    hi[2] = src[2];
    hi[3] = src[3];
    lo[0] = hot[0];
    lo[1] = hot[1];
    lo[2] = hot[2];
    lo[3] = hot[3];
    hi[0] *= 16;
    hi[1] *= 16;
    hi[2] *= 16;
    hi[3] *= 16;
    lo[0] *= 16;
    lo[1] *= 16;
    lo[2] *= 16;
    lo[3] *= 16;
    func_00141020(obj, arg1, hi, arg3, lo);
}
