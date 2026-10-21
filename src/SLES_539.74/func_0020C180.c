// range: 0x20C180 0x20C210
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s32, s32);           /* extern */
extern M2C_UNK D_003C7720 __attribute__((section(".data")));

void func_0020C180(void *arg0, s32 arg1) {
    char *obj;
    s32 idx;
    char *p;

    obj = arg0;
    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        p = 0;
    } else {
        p = obj + idx * 0xC0 + 0x5610;
    }
    DebugPrintf(&D_003C7720, arg1, M2C_FIELD(p, s32 *, 0xC));

    idx = M2C_FIELD(obj, s32 *, 0x5874);
    if (idx < 0) {
        p = 0;
    } else {
        p = obj + idx * 0xC0 + 0x5610;
    }
    M2C_FIELD(p, s32 *, 0xC) = arg1;
}
