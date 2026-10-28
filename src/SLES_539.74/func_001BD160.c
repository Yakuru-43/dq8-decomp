// range: 0x1BD160 0x1BD1A0
#include "common.h"

void func_002BD800(s32, s32);

s32 func_001BD160(char *arg0) {
    s32 val;

    if (*(s32 *)arg0 == 1) {
        val = (s32)*(float *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_002BD800(val, 0);
    return 1;
}
