// range: 0x13F630 0x13F6C0
#include "common.h"

void func_0013F630(char *arg0) {
    s32 *temp_t0;
    s32 *temp_a3;
    s32 *temp_a2;

    M2C_FIELD(arg0, char **, 0xF8) = M2C_FIELD(arg0, char **,0xF4);
    M2C_FIELD(arg0, char **, 0xFC) = M2C_FIELD(arg0, char **,0xF8);
    temp_t0 = (s32 *) M2C_FIELD(arg0, char **,0xF4);
    M2C_FIELD(temp_t0, s32 *, 0) = 0;
    M2C_FIELD(temp_t0, s32 *, 4) = 0;
    M2C_FIELD(temp_t0, s32 *, 8) = 0;
    M2C_FIELD(temp_t0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 **, 0x104) = temp_t0;
    M2C_FIELD(arg0, s32 **, 0x108) = temp_t0 + 3;
    M2C_FIELD(arg0, char **, 0xF4) = M2C_FIELD(arg0, char **,0xF4) + 0x10;
    temp_a3 = (s32 *) M2C_FIELD(arg0, char **,0xF4);
    M2C_FIELD(arg0, s32 **, 0x100) = temp_a3;
    M2C_FIELD(temp_a3, s32 *, 0) = 0x8000;
    M2C_FIELD(temp_a3, s32 *, 4) = 0x10000000;
    M2C_FIELD(temp_a3, s32 *, 8) = 14;
    M2C_FIELD(temp_a3, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, char **, 0xF4) = M2C_FIELD(arg0, char **,0xF4) + 0x10;
    temp_a2 = (s32 *) M2C_FIELD(arg0, char **,0xF4);
    M2C_FIELD(temp_a2, s64 *, 0) = M2C_FIELD(arg0, s64 *, 0x70);
    M2C_FIELD(temp_a2, s64 *, 8) = 0;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) temp_a2 + 0x10;
}
