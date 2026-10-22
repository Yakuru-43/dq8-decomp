// range: 0x3026A0 0x302740
#include "common.h"

f32 func_0013B9C0(void);                       /* extern */
extern f32 D_003DF54C;

void func_003026A0(s32 *obj) {
    f32 *timer;
    f32 x;

    timer = (f32 *)obj;
    if (obj[1] == 0 || obj[4] == 0) {
        obj[9] = 0x42480000; /* 50.0f */
    } else {
        x = D_003DF54C * (6.0f + func_0013B9C0());
        if (x < 5.0f) {
            x = 5.0f;
        }
        timer[9] = x * *(f32 *)((char *)obj[4] + 0x48);
    }
    timer[10] = timer[9];
}
