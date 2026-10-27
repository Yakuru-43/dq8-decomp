// range: 0x4691C0 0x469200
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00469BE0(s32);                         /* extern */
s32 func_201CD0();                                  /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_004792D8 __attribute__((section(".data")));

void func_004691C0(void) {
    char *temp_v0;

    temp_v0 = func_370FA0(func_201CD0(), &D_004792D8);
    func_00469BE0(M2C_FIELD(temp_v0, s16 *, 0x10) + (M2C_FIELD(temp_v0, s16 *, 0x12) * 4));
}
