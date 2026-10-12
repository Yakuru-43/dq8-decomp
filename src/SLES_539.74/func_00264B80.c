// range: 0x264B80 0x264BB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0();                            /* extern */
extern s32 D_003E0D14;

void func_00264B80(s32 arg0) {
    D_003E0D14 = arg0;

    if (!(arg0 != 0)) {
        return;
    }

    func_00130FD0();
}
