// range: 0x2CD710 0x2CD7A0
#include "common.h"

extern char *func_0016D5B0(char *, s32);

f32 func_002CD710(char *arg0, char *arg1, char *arg2) {
    f32 var_f1;
    f32 var_f0;
    char *temp_s0;
    char *temp_v0;
    char *temp_a0;
    char *temp_v1;

    temp_s0 = func_0016D5B0(arg0, (s32)*(s16 *)(arg1 + 0xC));
    temp_v0 = func_0016D5B0(arg0, (s32)*(s16 *)(arg2 + 0xC));
    temp_a0 = *(char **)(arg1 + 0x20);
    temp_v1 = *(char **)(arg2 + 0x20);
    if (temp_a0 == NULL) {
        var_f1 = *(f32 *)(temp_s0 + 0x4C8);
    } else {
        var_f1 = (f32)*(s32 *)(temp_a0 + 0x74);
    }
    if (temp_v1 == NULL) {
        var_f0 = *(f32 *)(temp_v0 + 0x4C8);
    } else {
        var_f0 = (f32)*(s32 *)(temp_v1 + 0x74);
    }
    return var_f1 + var_f0;
}
