// range: 0x298BE0 0x298CB0
#include "common.h"

extern s64 func_00296F60(char *);
extern s32 func_002991E0(char *, char *, s32, s32);

s64 func_00298BE0(char *arg0) {
    char *temp_v0;
    char *temp_a0;
    s64 temp_v0_2;
    char *temp_a1;
    char *temp_s1;
    s64 temp_s0;
    s32 var_a3;

    temp_v0 = *(char **)(arg0 + 0x488);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a0 = *(char **)(temp_v0 + 0x1C);
    if (temp_a0 == NULL) {
        return 0;
    }
    temp_v0_2 = func_00296F60(temp_a0);
    var_a3 = 0;
    temp_a1 = *(char **)(*(char **)(arg0 + 0x488) + 0x1C);
    temp_s1 = temp_a1 + 0xE0;
    temp_s0 = *(s64 *)(temp_a1 + 0x158);
    if (temp_v0_2 & 0x80000) {
        var_a3 = func_002991E0(arg0, temp_a1, 0x13, 0) & 0xFF;
    }
    if (var_a3 == 0 && (temp_v0_2 & 0x100)) {
        func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 8, var_a3);
    }
    return temp_s0 & (temp_s0 ^ *(s64 *)(temp_s1 + 0x78));
}
