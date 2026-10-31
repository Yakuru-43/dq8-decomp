// range: 0x233AB0 0x233BC0
#include "common.h"

extern void func_00234F60(char *);
extern void func_00235C70(char *);

void func_00233AB0(char *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_s0;
    s32 var_s0_2;
    char *temp_v1;
    char *temp_a0_2;
    char *var_a1;
    s32 temp_a0;
    char *field_ptr;

    var_s1 = arg1;
    if (arg1 < 0) {
        var_s1 = *(s32 *)(arg0 + 0x20);
    }
    var_s0 = 0;
    while (var_s0 < *(s32 *)(arg0 + 0x18)) {
        if (var_s0 >= 0 && var_s0 < *(s32 *)(arg0 + 0x18)) {
            var_a1 = *(char **)(arg0 + 0x1C) + (var_s0 * 0x830);
        } else {
            var_a1 = NULL;
        }
        if (var_a1 != NULL && *(s32 *)(var_a1 + 4) == var_s1) {
            *(s32 *)(var_a1 + 0) = -1;
            *(s32 *)(var_a1 + 4) = -1;
            func_00234F60(var_a1 + 0xC);
        }
        var_s0 += 1;
    }
    var_s0_2 = 0;
    do {
        temp_v1 = arg0 + (var_s0_2 * 4);
        field_ptr = temp_v1 + 8;
        temp_a0_2 = *(char **)(field_ptr);
        if (temp_a0_2 != NULL && *(s16 *)(temp_a0_2 + 0x90) == arg1) {
            func_00235C70(temp_a0_2);
            *(char **)(field_ptr) = NULL;
        }
        var_s0_2 += 1;
    } while (var_s0_2 < 4);
}
