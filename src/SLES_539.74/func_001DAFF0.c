// range: 0x1DAFF0 0x1DB090
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014DF10();    /* extern */
M2C_UNK func_0014E8A0();                         /* extern */

char *func_001DAFF0(char *arg0) {
    func_0014E8A0(arg0 + 0x2C);
    func_0014E8A0(arg0 + 0x84);
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0x1E;
    M2C_FIELD(arg0, s32 *, 0x28) = 3;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x44480000;
    M2C_FIELD(arg0, s32 *, 0x10) = 8;
    M2C_FIELD(arg0, s32 *, 0x18) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x44480000;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x8700;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x5280;
    func_0014DF10(arg0 + 0x2C, 0, 0);
    func_0014DF10(arg0 + 0x84, 0, 0);
    return arg0;
}
