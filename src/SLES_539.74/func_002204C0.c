// range: 0x2204C0 0x220570
#include "common.h"

s32 func_00220C10(void *, s32, s32);                /* extern */
s32 func_00164100(M2C_UNK *, s32);                  /* extern */
s32 func_0022B350(s32, s32);                        /* extern */
s32 func_0021B220(void *);                           /* extern */
extern s32 D_003DFC1C;
extern s32 D_003DFC20;
extern s32 D_003DFC24;
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_002204C0(void *arg0) {
    s32 ret;

    if (arg0 == 0) {
        return 2;
    }
    ret = 0;
    if (func_00220C10(arg0, 0, 1) == 0) {
        if (func_00164100(&D_003FAFB0, D_003DFC20 | 0x181) != 0) {
            ret = 2;
        } else {
            if (func_0022B350(D_003DFC1C | D_003DFC24 | 0x204, 0) != 0) {
                s32 found;

                found = func_0021B220(arg0);
                ret = 1;
                if (found == 1) {
                    ret = 2;
                }
            }
        }
    }
    return ret;
}
