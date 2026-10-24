// range: 0x307AB0 0x307B10
#include "common.h"

void func_00307AB0(void *arg0, f32 arg1) {
    f32 *acc = (f32 *)((char *)arg0 + 0x1724);
    f32 *base = (f32 *)((char *)arg0 + 0x1700);

    *acc = *acc + arg1;
    if (6000.0f <= *acc) {
        base[9] = *acc - 6000.0f;
        *(s32 *)((char *)arg0 + 0x6BC) &= ~0x02000000;
    }
}
