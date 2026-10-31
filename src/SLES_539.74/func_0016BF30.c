// range: 0x16BF30 0x16BF80
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014DEE0(char *);
void func_0014DF10(char *, s32, s32);
void func_0016BF30(char *arg0, s32 arg1, s32 arg2) {
    char *temp_s0;

    temp_s0 = arg0 + 0x38;
    if (temp_s0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0) = -1;
        func_0014DF10(temp_s0, arg1, arg2);
        func_0014DEE0(temp_s0);
        M2C_FIELD(arg0, s32 *, 0x508) = 0;
    }
}
