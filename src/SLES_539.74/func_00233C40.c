// range: 0x233C40 0x233CF0
#include "common.h"

extern f32 D_003DF598;

void func_00233C40(char *arg0, s32 arg1, s32 arg2, f32 arg3) {
    char *var_a3;
    s32 var_t1;

    if (arg1 < 0) {
        return;
    }
    var_t1 = 0;
    while (var_t1 < *(s32 *)(arg0 + 0x18)) {
        var_a3 = *(char **)(arg0 + 0x1C);
        var_a3 += var_t1 * 0x830;
        if (arg1 == *(s32 *)var_a3) {
            goto found;
        }
        var_t1 += 1;
    }
    var_a3 = NULL;
found:
    if (var_a3 == NULL) {
        return;
    }
    *(s32 *)(var_a3 + 0x828) = arg2;
    *(f32 *)(var_a3 + 0x82C) = arg3;
    if (arg3 < 0.0f) {
        if (*(s32 *)(var_a3 + 0x828) == 0) {
            *(f32 *)(var_a3 + 0x824) = 0.0f;
        }
        if (*(s32 *)(var_a3 + 0x828) == 1) {
            *(f32 *)(var_a3 + 0x824) = 1.0f;
        }
        *(f32 *)(var_a3 + 0x82C) = D_003DF598;
    }
}
