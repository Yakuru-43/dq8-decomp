// range: 0x468520 0x468560
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
s32 func_370FA0(s32, M2C_UNK *);                    /* extern */
M2C_UNK func_3715D0(s32);                           /* extern */
extern M2C_UNK D_00473890 __attribute__((section(".data")));

void func_00468520(void) {
    func_3715D0(func_370FA0(func_201CD0(), &D_00473890));
}
