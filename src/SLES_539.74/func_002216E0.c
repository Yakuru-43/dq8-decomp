// range: 0x2216E0 0x221770
#include "common.h"

M2C_UNK *func_003640B0(s32);                        /* extern */
void func_002F6010(s32, s32, void *);               /* extern */
extern M2C_UNK D_003C81E0 __attribute__((section(".data")));

void func_002216E0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == 0) {
        func_002F6010(arg0, arg1, &D_003C81E0);
    } else {
        M2C_UNK *var_v0 = func_003640B0(arg2);
        if (var_v0 == 0) {
            func_002F6010(arg0, arg1, &D_003C81E0);
        } else {
            func_002F6010(arg0, arg1, var_v0);
        }
    }
}
