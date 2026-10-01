// range: 0x20D920 0x20D970
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0020D970(s32, s32);                    /* extern */
M2C_UNK func_00210660(s32, s32, M2C_UNK);           /* extern */
extern s32 D_003E08D0;

void func_0020D920(s32 arg0, M2C_UNK arg1) {
    if ((arg0 != 0) && (D_003E08D0 != 0)) {
        func_00210660(D_003E08D0, arg0, arg1);
        func_0020D970(D_003E08D0, arg0 + 0x78);
    }
}
