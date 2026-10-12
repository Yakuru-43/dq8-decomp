// range: 0x13EB30 0x13EBB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0015BDE0();                 /* extern */
M2C_UNK func_0015BF50();                         /* extern */

void func_0013EB30(char *arg0, s32 arg1) {
    char *temp_t0;


    if (!(arg1 != 0)) {
        return;
    }

    func_0015BF50(arg0 + 0x78);
    func_0015BDE0(arg0 + 0x78, M2C_FIELD(arg0, s32 *, 0xE0));
    temp_t0 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_t0, s64 *, 0) = 0;
    M2C_FIELD(temp_t0, s64 *, 8) = 0x3F;
    M2C_FIELD(temp_t0, s64 *, 0x10) = (s64) M2C_FIELD(arg0, s64 *, 0xB8);
    M2C_FIELD(temp_t0, s64 *, 0x18) = 0x14;
    M2C_FIELD(temp_t0, s64 *, 0x20) = (s64) M2C_FIELD(arg0, s64 *, 0xB0);
    M2C_FIELD(temp_t0, s64 *, 0x28) = 6;
    M2C_FIELD(temp_t0, s64 *, 0x30) = (s64) M2C_FIELD(arg0, s64 *, 0xC0);
    M2C_FIELD(temp_t0, s64 *, 0x38) = 8;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (temp_t0 + 0x40);
}
