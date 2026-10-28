// range: 0x206D10 0x206D70
#include "common.h"

void func_00207550(char *, char *);

s32 func_00206D10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    s32 temp_v0;

    if (arg1 == 4) {
        if (arg3 == 4) {
            var_s0 = arg2;
            while (var_s0 > 0) {
                temp_v0 = arg0 + (var_s0 << 2);
                func_00207550((char *)(temp_v0 + 0xC0), (char *)(temp_v0 + 0xBC));
                var_s0 -= 1;
            }
        }
    }
    return 0;
}
