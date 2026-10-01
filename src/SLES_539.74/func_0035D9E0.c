// range: 0x35D9E0 0x35DAD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0(s64);                             /* extern */
s16 func_002B8090();                                /* extern */
s32 func_002D05A0(s32);                             /* extern */
M2C_UNK func_00304C60(s32, s16);                    /* extern */
M2C_UNK func_00358B10(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0035C680(void *, M2C_UNK);             /* extern */
M2C_UNK func_0035D5A0(void *);                      /* extern */
s64 func_0035DE00(void *);                          /* extern */
M2C_UNK func_0035E520(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_0035E590(void *);                          /* extern */
s32 func_0035F5B0();                                /* extern */
extern M2C_UNK D_0042D940 __attribute__((section(".data")));

void func_0035D9E0(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s8 arg3) {
    s64 temp_a0;

    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x140) = 0;
    M2C_FIELD(arg0, s32 *, 0x144) = 0;
    M2C_FIELD(arg0, s8 *, 0x560) = arg3;
    M2C_FIELD(arg0, s8 *, 0x561) = 0;
    M2C_FIELD(arg0, s32 *, 0x568) = func_0035F5B0();
    M2C_FIELD(arg0, s16 *, 0x56C) = func_002B8090();
    func_0035D5A0(arg0);
    func_0035C680(arg0, 1);
    func_0035E520(arg0, 2, 1);
    if (func_0035E590(arg0) == 1) {
        func_00358B10(&D_0042D940, arg0, arg1, arg2);
    }
    temp_a0 = (s64) (func_0035DE00(arg0) << 0x38) >> 0x38;
    if (temp_a0 == 5) {
        func_00304C60(func_002D05A0(func_001814D0(temp_a0)), M2C_FIELD(arg0, s16 *, 0xC));
    }
}
