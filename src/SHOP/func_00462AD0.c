// range: 0x462AD0 0x462B20
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
M2C_UNK func_205D30(s32, s32);                      /* extern */
s32 func_370FA0(s32, M2C_UNK *);                    /* extern */
s32 func_3715D0(s32);                               /* extern */
extern M2C_UNK D_004736C0 __attribute__((section(".data")));

void func_00462AD0(void) {
    s32 temp_s0;

    temp_s0 = func_3715D0(func_370FA0(func_201CD0(), &D_004736C0));
    func_205D30(func_181420(), temp_s0);
}
