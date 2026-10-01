// range: 0x27F750 0x27F7F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0015DDC0(char *, char *);              /* extern */
M2C_UNK func_00281660(char *);                      /* extern */

void func_0027F750(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0x774) = 0;
    M2C_FIELD(arg0, s32 *, 0x770) = 0;
    M2C_FIELD(arg0, s32 *, 0x778) = 0;
    M2C_FIELD(arg0, s32 *, 0x5A0) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5A4) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5A8) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5AC) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5B0) = 0;
    M2C_FIELD(arg0, s32 *, 0x5B4) = 0;
    M2C_FIELD(arg0, s32 *, 0x5B8) = 0;
    M2C_FIELD(arg0, s32 *, 0x5BC) = 0;
    M2C_FIELD(arg0, s32 *, 0x5D0) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5D4) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5D8) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5DC) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x5E0) = 0;
    M2C_FIELD(arg0, s32 *, 0x5E4) = 0;
    M2C_FIELD(arg0, s32 *, 0x5E8) = 0;
    M2C_FIELD(arg0, s32 *, 0x5EC) = 0;
    func_0015DDC0(arg0 + 0x630, arg0 + 0x6F0);
    M2C_FIELD(arg0, s32 *, 0x63C) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x77C) = 0x41700000;
    M2C_FIELD(arg0, s32 *, 0x780) = 0;
    M2C_FIELD(arg0, s32 *, 0x784) = 0;
    M2C_FIELD(arg0, s32 *, 0x788) = 0;
    func_00281660(arg0);
}
