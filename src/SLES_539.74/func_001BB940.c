// range: 0x1BB940 0x1BB990
#include "common.h"

void func_00170510(char *, s32);
s32 func_001A2160(void);

s32 func_001BB940(char *arg0) {
    s32 val;
    if (*(s32 *)arg0 == 1) {
        val = (s32)*(float *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_00170510((char *)func_001A2160(), val);
    return 1;
}
