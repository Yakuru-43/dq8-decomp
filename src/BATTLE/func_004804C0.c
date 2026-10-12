// range: 0x4804C0 0x480520
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_0045F750(M2C_UNK *, M2C_UNK, s32);     /* extern */
M2C_UNK func_00479C50(char *);                      /* extern */
extern M2C_UNK D_42E830 __attribute__((section(".data")));

s32 func_004804C0(s32 arg0, char *arg1) {
    s32 temp_s0;
    s32 temp_v0;
    char *temp_a0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0xB4);
    if (0 == temp_v0) {
        return 1;
    }
    temp_a0= (char *) ( temp_v0 + 8);
    if (NULL == temp_a0) {
        return 1;
    }
    temp_s0 = M2C_FIELD(temp_a0, s32 *, 4);
    func_00479C50(temp_a0);
    func_0045F750(&D_42E830, 0, temp_s0);
    return 0;
}
