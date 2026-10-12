// range: 0x166D00 0x166D50
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013D2B0(char *);                      /* extern */

void func_00166D00(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x42340000;
    func_0013D2B0(arg0 + 0x10);
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s128 *, 0x50) = 0;
    M2C_FIELD(arg0, s128 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0xBF800000;
    func_0013D2B0(arg0 + 0x80);
}
