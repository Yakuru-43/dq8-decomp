// range: 0x464C30 0x464C60
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_00479140 __attribute__((section(".data")));

s16 func_00464C30(void) {
    return M2C_FIELD(func_370FA0(func_201CD0(), &D_00479140), s16 *, 0x12);
}
