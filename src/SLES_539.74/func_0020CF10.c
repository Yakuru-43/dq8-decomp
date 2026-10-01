// range: 0x20CF10 0x20CF90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014DF10(char *, char *, M2C_UNK);     /* extern */
M2C_UNK func_001746D0(M2C_UNK);                     /* extern */
M2C_UNK func_00176500(M2C_UNK);                     /* extern */
M2C_UNK func_0020CF90(char *);                      /* extern */

void func_0020CF10(char *arg0) {
    func_001746D0(2);
    func_0020CF90(arg0);
    M2C_FIELD(arg0, s32 *, 0x5F98) = -1;
    M2C_FIELD(arg0, s32 *, 0x5F9C) = -1;
    func_0014DF10(arg0 + 0x63A0, arg0 + 0x5FA0, 0x40);
    func_00176500(2);
    M2C_FIELD(arg0, s32 *, 0x6400) = 0;
    M2C_FIELD(arg0, s32 *, 0x63F8) = 0;
    M2C_FIELD(arg0, s32 *, 0x6404) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x63FC) = -1;
    M2C_FIELD(arg0, s32 *, 0x6408) = 0;
    M2C_FIELD(arg0, s32 *, 0x640C) = 0;
    func_0020CF90(arg0);
}
