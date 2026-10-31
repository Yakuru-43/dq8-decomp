// range: 0x2E3E80 0x2E3EF0
#include "common.h"

s32 func_002E3E80(s32 arg0, s32 arg1) {
    s32 var_t0;
    s32 var_a3;
    u16 temp_v0;

    if (arg1 < 0) {
        return -1;
    }
    if (arg1 == 0) {
        return 0;
    }
    var_t0 = 0;
    var_a3 = 0;
    while (var_a3 < 0x200) {
        temp_v0 = *(u16 *)(arg0 + (var_a3 * 8) + 0x198);
        if (temp_v0 == 0xFF01) {
            return -1;
        }
        if (temp_v0 == 0xFF03) {
            var_t0++;
            if (var_t0 == arg1) {
                return var_a3 + 1;
            }
        }
        var_a3++;
    }
    return -1;
}
