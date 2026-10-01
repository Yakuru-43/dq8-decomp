// range: 0x3438B0 0x3439E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, s32);                    /* extern */
s32 func_0018F100(s32);                             /* extern */
s32 func_0018F130(char *);                          /* extern */
s32 func_003439E0(char *);                          /* extern */

void func_003438B0(s32 arg0, char *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s8 temp_v1;

    temp_v0 = func_003439E0(arg1);
    if (temp_v0 == 1) {
        if (func_0018F100(0x1B) != 0) {
            temp_v1 = M2C_FIELD(arg1, s8 *, 0xA);
            if ((temp_v1 >= 0x61) && (temp_v1 < 0x7B)) {
                temp_v0_2 = func_0018F100(func_0018F130(arg1 + 0xA));
                if (temp_v0_2 != 0) {
                    func_001340C0(arg0, temp_v0_2);
                } else {
                    func_001340C0(arg0, func_0018F100(0x1B));
                }
            } else {
                func_001340C0(arg0, func_0018F100(0x1B));
            }
        }
    }
    if (temp_v0 != 2) {

    } else {
        temp_v0_3 = func_0018F130(arg1 + 9);
        if (func_0018F100(temp_v0_3) != 0) {
            func_001340C0(arg0, func_0018F100(temp_v0_3));
        }
    }
}
