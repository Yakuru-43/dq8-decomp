// range: 0x1B9B20 0x1B9B70
#include "common.h"

void func_00197A80(s32);

s32 func_001B9B20(char *arg0, s32 arg1) {
    s32 val;
    if (arg1 != 1) {
        return 0;
    }
    if (*(s32 *)arg0 == 1) {
        f32 f = *(f32 *)(arg0 + 4);
        val = (s32)f;
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_00197A80(val);
    return 1;
}
