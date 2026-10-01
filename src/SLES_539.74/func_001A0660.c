// range: 0x1A0660 0x1A0690
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0019F470(M2C_UNK *);                   /* extern */
extern M2C_UNK D_00410DA8 __attribute__((section(".data")));

s32 func_001A0660(void) {
    func_0019F470(&D_00410DA8);
    return 1;
}
