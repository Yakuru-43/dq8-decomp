// range: 0x221E90 0x221F50
#include "common.h"

extern char * func_00181420(void);
extern s32 func_00201C00(char *);
extern s32 func_002061F0(s32, s32);
extern s32 func_00201BE0(s32, s32);

s32 func_00221E90(s32 arg0) {
    char *temp_v0;
    s32 var_s0;

    temp_v0 = (char *)func_002061F0((s32)func_00181420(), arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    if (func_00201C00(temp_v0) > 0) {
        var_s0 = 0;
        if (func_00201BE0((s32)temp_v0, 0x200000) != 0) {
            var_s0 = 2;
        } else if (func_00201BE0((s32)temp_v0, 0x400000) != 0) {
            var_s0 = 3;
        } else if (arg0 != 0) {
            if (func_00201BE0((s32)temp_v0, 0x02000000) != 0) {
                var_s0 = 4;
            }
        }
        return var_s0;
    }
    return 1;
}
