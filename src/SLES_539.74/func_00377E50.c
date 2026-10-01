// range: 0x377E50 0x377EB0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s8 *, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK func_0025FBD0(M2C_UNK *, s8 *);             /* extern */
extern M2C_UNK D_0040EE30 __attribute__((section(".data")));
extern s8 D_00458A80 __attribute__((section(".data")));

void func_00377E50(void) {
    if (D_00458A80 != 0) {
        func_0025FBD0(&D_0040EE30, &D_00458A80);
        func_00131188(&D_00458A80, 0, 0xF0);
    }
}
