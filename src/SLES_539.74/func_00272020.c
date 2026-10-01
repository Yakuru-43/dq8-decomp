// range: 0x272020 0x272040
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00272020(char *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, u8 *, 8) = (u8) *arg1;
    M2C_FIELD(arg0, char **, 0xC) = (char *) (arg0 + 4);
    return arg0;
}
