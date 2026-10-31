// range: 0x46C5C0 0x46C610
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
M2C_UNK func_205D30(s32, s16);                      /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_00479438 __attribute__((section(".data")));

void func_0046C5C0(void) {
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0 = func_201CD0();
    temp_s0_2 = func_181420();
    func_205D30(temp_s0_2, M2C_FIELD(func_370FA0(temp_s0, &D_00479438), s16 *, 0x12));
}
