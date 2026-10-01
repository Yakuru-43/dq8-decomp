// range: 0x383E80 0x383EC0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205D30(s32, s16);                        /* extern */
M2C_UNK func_00359CF0(M2C_UNK *, s32);              /* extern */
extern void *D_003E0868;
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

void func_00383E80(void) {
    func_00359CF0(&D_00421AD0, func_00205D30(func_00181420(), M2C_FIELD(D_003E0868, s16 *, 0x92)));
}
