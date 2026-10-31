// range: 0x46B340 0x46B3D0
#include "common.h"

s32 func_0046DDF0(s32);                             /* extern */
void func_2D38E0(s32, s32, s32, s32);                /* extern */

void func_0046B340(u32 arg0) {
    s32 obj;
    u8 t;
    u8 on;

    obj = func_0046DDF0(arg0);
    t = !(arg0 > 0);
    on = !t;
    func_2D38E0(obj, 0x1F53, on, -1);
    func_2D38E0(obj, 0x1F44, on, -1);
    func_2D38E0(obj, 0x1F69, on, -1);
}
