// range: 0x26A0A0 0x26A0E0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xB0];
    s32 unkB0;
    s32 unkB4;
} S_arg0;

void func_0026A0A0(S_arg0 *arg0, s32 arg1, char *arg2) {
    char *temp_a3;

    if (arg1 >= 0) {
        temp_a3= (char *) ( arg0->unkB4 + (arg1 * 0x10));
        M2C_FIELD(temp_a3, s128 *, 0)= (s128) M2C_FIELD(arg2, s128 *, 0);
        M2C_FIELD(temp_a3, s128 *, 0x10)= (s128) M2C_FIELD(arg2, s128 *, 0x10);
        M2C_FIELD(temp_a3, s128 *, 0x20)= (s128) M2C_FIELD(arg2, s128 *, 0x20);
        M2C_FIELD(temp_a3, s128 *, 0x30)= (s128) M2C_FIELD(arg2, s128 *, 0x30);
        arg0->unkB0 = arg1;
    }
}
