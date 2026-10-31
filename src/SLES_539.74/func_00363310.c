// range: 0x363310 0x363370
#include "common.h"

f32 func_0013D340(f32 *, f32 *);

s32 func_00363310(f32 *arg0, s128 *arg1) {
    if (!(func_0013D340(arg0, arg0 + 4) < 4.0f)) {
        *arg1 = *(s128 *)(arg0 + 4);
        return 1;
    }
    return 0;
}
