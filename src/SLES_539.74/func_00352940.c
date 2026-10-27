// range: 0x352940 0x352980
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

char * func_0016D5B0(char *, s32);
void func_00352940(char *arg0, s32 arg1) {
    s8 *temp_v0;

    temp_v0= (signed char *) ( func_0016D5B0(arg0, 0x20));

    if (!(temp_v0 != NULL)) {
        return;
    }

    M2C_FIELD(temp_v0, s32 *, 0x4F4) = arg1;
}
