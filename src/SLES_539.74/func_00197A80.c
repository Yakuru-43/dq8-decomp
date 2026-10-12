// range: 0x197A80 0x197AB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001978C0();                            /* extern */
extern s8 D_003E05BC;
extern s8 D_0040FFA2 __attribute__((section(".data")));

void func_00197A80(s8 arg0) {

    if (!(D_003E05BC != 0)) {
        return;
    }

    D_0040FFA2 = arg0;
    func_001978C0();
}
