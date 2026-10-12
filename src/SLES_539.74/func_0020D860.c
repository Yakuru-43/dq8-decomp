// range: 0x20D860 0x20D890
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0020D890(s32, s32);                    /* extern */
extern s32 D_003E08D0;

void func_0020D860(s32 arg0) {

    if (!(D_003E08D0 != 0)) {
        return;
    }

    func_0020D890(D_003E08D0, arg0);
}
