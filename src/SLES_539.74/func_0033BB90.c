// range: 0x33BB90 0x33BD00
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
char *func_001897E0(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_002562C0(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_003081D0(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_003084D0(s32, M2C_UNK);                    /* extern */
extern M2C_UNK D_003D2C20 __attribute__((section(".data")));
extern M2C_UNK D_003D2C40 __attribute__((section(".data")));
extern s8 D_004536A0 __attribute__((section(".data")));

void func_0033BB90(s32 arg0, s32 arg1) {
    s32 var_s2;
    s32 var_s3;
    char *temp_s2;
    char *temp_v0;


    if (!(arg0 != 0)) {
        return;
    }

    if (D_004536A0 == 0) {
        return;
    }
    var_s3 = 0;
    if (func_003084D0(func_001814D0(), 0x2B) == 0) {
        var_s3 = 1;
    }
    var_s2 = 0;
    if (func_003084D0(func_001814D0(), 0x2B) == 0) {
        var_s2 = 1;
    }
    temp_v0 = func_001897E0(arg0, &D_003D2C20, 6);
    if (temp_v0 != NULL) {
        if (var_s2 != 0) {
            M2C_FIELD(temp_v0, s16 *, 0x32) = 0;
            M2C_FIELD(temp_v0, s32 *, 0x44) = 0;
        } else {
            M2C_FIELD(temp_v0, s16 *, 0x32) = 1;
            M2C_FIELD(temp_v0, s32 *, 0x44) = 1;
        }
    }
    temp_s2 = func_001897E0(arg0, &D_003D2C40, 6);
    if ((arg1 != 0) && (var_s3 == 0)) {
        func_003081D0(func_001814D0(), 5, 1);
        if (temp_s2 != NULL) {
            M2C_FIELD(temp_s2, s32 *, 0x44) = 1;
            M2C_FIELD(temp_s2, s16 *, 0x32) = 1;
        }
    } else {
        func_003081D0(func_001814D0(), 5, 0);
        if (temp_s2 != NULL) {
            M2C_FIELD(temp_s2, s32 *, 0x44) = 0;
            M2C_FIELD(temp_s2, s16 *, 0x32) = 0;
        }
    }
    func_002562C0(arg0, 0x1C, 0);
}
