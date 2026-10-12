// range: 0x21D150 0x21D1D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013E080(char *);                      /* extern */
M2C_UNK func_0015DBF0();                            /* extern */

void func_0021D150(char *arg0) {
    func_0015DBF0();
    M2C_FIELD(arg0, s32 *, 0x68) = 0x20;
    M2C_FIELD(arg0, s32 *, 0x64) = 0x20;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x20;
    func_0013E080(arg0 + 0x70);
    func_0013E080(arg0 + 0x80);
    func_0013E080(arg0 + 0x90);
    M2C_FIELD(arg0, s32 *, 0xA4) = 0;
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB0) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    M2C_FIELD(arg0, s32 *, 0xB8) = 0;
    M2C_FIELD(arg0, s32 *, 0xBC) = 0;
    M2C_FIELD(arg0, s32 *, 0xC0) = 0;
    M2C_FIELD(arg0, s128 *, 0xD0) = 0;
    M2C_FIELD(arg0, s128 *, 0xE0) = 0;
}
