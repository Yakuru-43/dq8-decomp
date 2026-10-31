// range: 0x469950 0x4699A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
s32 func_205D30(s32, s16);                          /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_00479330 __attribute__((section(".data")));

s32 func_00469950(s16 *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(func_370FA0(func_201CD0(), &D_00479330), s16 *, 0x12);
    return func_205D30(func_181420(), temp_s0);
}
