// range: 0x46E170 0x46E1C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
M2C_UNK func_205D30(s32, s32);                      /* extern */
s32 func_370FA0(s32, M2C_UNK *);                    /* extern */
s32 func_3715D0(s32);                               /* extern */
extern M2C_UNK D_00479500 __attribute__((section(".data")));

void func_0046E170(void) {
    s32 temp_s0;

    temp_s0 = func_181420();
    func_205D30(temp_s0, func_3715D0(func_370FA0(func_201CD0(), &D_00479500)));
}
