// range: 0x276030 0x2760C0
#include "common.h"

void func_00276030(char *arg0, char **arg1) {
    char *temp_a3;
    char *temp_a1;
    char *temp_a1_2;

    temp_a3 = *(char **)arg0;
    if (*arg1 == arg0) {
        *arg1 = temp_a3;
    }
    *(char **)arg0 = *(char **)(temp_a3 + 4);
    temp_a1 = *(char **)(temp_a3 + 4);
    if (temp_a1 != NULL) {
        *(s32 *)(temp_a1 + 8) = (s32)arg0 | (*(s32 *)(temp_a1 + 8) & 1);
    }
    *(s32 *)(temp_a3 + 8) = (*(s32 *)(arg0 + 8) & ~1) | (*(s32 *)(temp_a3 + 8) & 1);
    temp_a1_2 = (char *)((s32)*(s32 *)(arg0 + 8) & ~1);
    if (arg0 == *(char **)temp_a1_2) {
        *(char **)temp_a1_2 = temp_a3;
    } else {
        *(char **)(temp_a1_2 + 4) = temp_a3;
    }
    *(char **)(temp_a3 + 4) = arg0;
    *(s32 *)(arg0 + 8) = (s32)temp_a3 | (*(s32 *)(arg0 + 8) & 1);
}
