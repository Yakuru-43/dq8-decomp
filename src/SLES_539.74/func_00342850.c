// range: 0x342850 0x342860
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002B0050(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_004392A0 __attribute__((section(".data")));

void func_00342850(s32 arg0) {
    func_002B0050(&D_004392A0, arg0);
}
