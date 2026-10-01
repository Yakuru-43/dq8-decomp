// range: 0x263DA0 0x263DE0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00221F50(s32);                         /* extern */
extern s8 D_003E0D04;
extern s32 D_003E0D08;

void func_00263DA0(void) {
    if ((D_003E0D04 != 0) && (D_003E0D08 != 0)) {
        func_00221F50(D_003E0D08);
    }
}
