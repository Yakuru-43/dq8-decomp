// range: 0x20D830 0x20D860
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00210550(s32, s32);                    /* extern */
extern s32 D_003E08D0;

void func_0020D830(s32 arg0) {

    if (!(D_003E08D0 != 0)) {
        return;
    }

    func_00210550(D_003E08D0, arg0);
}
