// range: 0x2073D0 0x207450
#include "common.h"

extern void func_00131188(char *, s32, s32);

void func_002073D0(char *arg0) {
    s32 var_a3;
    s32 var_a2;
    char *temp_v1;

    func_00131188(arg0, 0, 0x880);
    var_a3 = 0;
    do {
        var_a2 = 0;
        do {
            temp_v1 = arg0 + (var_a3 * 10) + (var_a2 * 2);
            var_a2 += 1;
            *(s16 *)(temp_v1 + 0x840) = -1;
        } while (var_a2 < 5);
        var_a3 += 1;
    } while (var_a3 < 4);
}
