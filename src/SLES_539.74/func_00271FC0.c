// range: 0x271FC0 0x271FE0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00271FC0(char *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, u8 *, 8) = (u8) *arg1;
    M2C_FIELD(arg0, char **, 0xC) = (char *) (arg0 + 4);
    return arg0;
}
