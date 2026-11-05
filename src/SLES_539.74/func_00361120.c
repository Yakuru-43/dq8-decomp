// range: 0x361120 0x3611E0
#include "common.h"

typedef struct {
    s32 a00;                                /* 0x000 */
    s32 a04;                                /* 0x004 */
    s32 a08[3];                             /* 0x008 */
    s32 a14[3];                             /* 0x014 */
    s32 a20[3];                             /* 0x020 */
    s32 pad2C[0x42];                        /* 0x02C */
    s32 a134;                               /* 0x134 */
    s32 a138[6];                            /* 0x138 */
    s32 a150;                               /* 0x150 */
    s32 pad154[3];                          /* 0x154 */
    s32 a160;                               /* 0x160 */
    s32 pad164[0x598];                      /* 0x164 */
    s32 a17C4[3];                           /* 0x17C4 */
    s32 a17D0[3];                           /* 0x17D0 */
} DQState;

extern DQState D_00456E70 __attribute__((section(".data")));

void func_0014E860(void *);                           /* extern */

s32 func_00361120(void) {
    DQState *st;
    s32 *w;
    s32 i;

    st = &D_00456E70;
    i = 0;
    do {
        func_0014E860((char *)st + i * 88 + 0x2C);
        w = (s32 *)st + i;
        i = i + 1;
        w[0x5F1] = 0;
        w[0x5F4] = 0;
        w[2] = -1;
        w[5] = -1;
        w[8] = -1;
    } while (i < 3);
    st->a00 = -1;
    st->a150 = -1;
    st->a04 = 0;
    st->a160 = 0;
    st->a134 = 0;
    i = 0;
    do {
        st->a138[i] = 0;
        i = i + 1;
    } while (i < 6);
    return 0;
}
