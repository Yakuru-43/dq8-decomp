// range: 0x2CE6D0 0x2CE7D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0015F490();                            /* extern */
s32 func_00200800(M2C_UNK *);                       /* extern */
M2C_UNK func_002B6030(M2C_UNK);                     /* extern */
M2C_UNK func_002B8060();                            /* extern */
M2C_UNK func_002B9120(M2C_UNK, M2C_UNK);            /* extern */
s32 func_002C17B0();                                /* extern */
s32 func_002C17F0();                                /* extern */
M2C_UNK func_003125A0();                            /* extern */
void *func_00359CF0(M2C_UNK *, s32);                /* extern */
s32 func_0035F200(M2C_UNK *);                       /* extern */
M2C_UNK func_00386AC0(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_00456E30 __attribute__((section(".data")));
extern M2C_UNK D_004590F0 __attribute__((section(".data")));

s32 func_002CE6D0(void *arg0) {
    s32 var_s1;
    void *temp_v0;

    func_0015F490();
    func_003125A0();
    if (func_002C17F0() == 0) {
        goto block_1;
    }
    if (func_002C17B0() == 0x232C) {
        return 3;
    }
block_1:
    var_s1 = 0;
    do {
        temp_v0 = func_00359CF0(&D_00421AD0, var_s1);
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0xE0) == 0x10D)) {
            func_00386AC0(&D_004590F0, func_00200800(&D_004590F0));
        }
        var_s1 += 1;
    } while (var_s1 < 4);
    func_002B8060();
    if (func_0035F200(&D_00456E30) != 0) {
        func_002B9120(4, 0x19);
    }
    func_002B6030(0);
    M2C_FIELD(arg0, s16 *, 0x90) = -1;
    M2C_FIELD(arg0, s16 *, 0x8E) = -1;
    return 2;
}
