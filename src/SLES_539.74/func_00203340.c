// range: 0x203340 0x2033A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, void *);                 /* extern */
u32 func_001341D8(void *);                          /* extern */

void func_00203340(s32 arg0, void *arg1) {
    if (arg1 != NULL) {
        if (func_001341D8(arg1) >= 0x10U) {
            M2C_FIELD(arg1, s8 *, 0xF) = 0;
        }
        func_001340C0(arg0, arg1);
    }
}
