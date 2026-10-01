// range: 0x4684E0 0x468520
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
s32 func_370FA0(s32, M2C_UNK *);                    /* extern */
M2C_UNK func_3715D0(s32);                           /* extern */
extern M2C_UNK D_00473890 __attribute__((section(".data")));

void func_004684E0(void) {
    func_3715D0(func_370FA0(func_201CD0(), &D_00473890));
}
