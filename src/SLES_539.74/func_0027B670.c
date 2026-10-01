// range: 0x27B670 0x27B750
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00278940();                             /* extern */
M2C_UNK func_0027A490();                /* extern */
s32 func_002B0B10();                                /* extern */
M2C_UNK func_002B1AD0();                    /* extern */
M2C_UNK func_00368930();         /* extern */
extern s16 D_004207B0 __attribute__((section(".data")));
extern s16 D_004207B2 __attribute__((section(".data")));
extern s16 D_004207B6 __attribute__((section(".data")));
extern M2C_UNK D_0042D390 __attribute__((section(".data")));

void func_0027B670(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_00278940(func_001814D0());
    if (arg0 == 0) {
        func_00368930(&D_0042D390, D_004207B0, 2);
        D_004207B2 = 0x63;
        D_004207B6 = 0;
    }
    if (arg0 == 1) {
        func_00368930(&D_0042D390, D_004207B0, (func_002B0B10() >= 3) & 0xFF);
        func_002B1AD0(temp_s0, D_004207B0);
        func_0027A490(D_004207B0, 1);
        D_004207B2 = 0x63;
        D_004207B6 = 1;
    }
}
