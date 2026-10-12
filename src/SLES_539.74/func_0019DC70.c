// range: 0x19DC70 0x19DCE0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0019DC70(char *arg0) {
    s32 *temp_v1;
    s32 var_a1;

    var_a1 = 0;
    do {
        temp_v1= (int *) ( arg0 + (var_a1 * 4));
        var_a1 += 1;
        *temp_v1 = 0;
    } while (var_a1 < 3);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x18) = 0x10;
    M2C_FIELD(arg0, s8 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x830) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x834) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x838) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x83C) = 0x437F0000;
    M2C_FIELD(arg0, s32 *, 0x840) = 0;
    M2C_FIELD(arg0, s32 *, 0x844) = 0;
    M2C_FIELD(arg0, s32 *, 0x848) = 0;
    M2C_FIELD(arg0, s32 *, 0x84C) = 0x42800000;
    M2C_FIELD(arg0, s32 *, 0x850) = 0;
    M2C_FIELD(arg0, s32 *, 0x854) = 0;
}
