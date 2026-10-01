// range: 0x2B91C0 0x2B9210
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002EA2A0(s32, s32);                    /* extern */
M2C_UNK func_002F7440(s32);                         /* extern */
extern s32 D_003E0FCC;

void func_002B91C0(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (D_003E0FCC != 0)) {
        if (arg1 != 0) {
            func_002EA2A0(D_003E0FCC, arg1 + 0x44B);
            return;
        }
        func_002F7440(D_003E0FCC);
    }
}
