// range: 0x191FF0 0x192080
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
M2C_UNK func_00190D40(s32);                         /* extern */
s32 func_00192080(s32, s32);                        /* extern */
M2C_UNK func_002F6640(s32, s32);                    /* extern */
extern s32 D_003E0598;

void func_00191FF0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    if ((arg0 != 0) && (D_003E0598 != 0)) {
        func_00190D40(D_003E0598);
        temp_v0 = func_00192080(D_003E0598, (arg1 >> 4) + 1);
        func_00130FD0(temp_v0, arg0, arg1);
        if (arg2 != 0) {
            func_002F6640(arg2, temp_v0);
        }
    }
}
