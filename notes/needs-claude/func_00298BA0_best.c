// range: 0x298BA0 0x298BE0
// best attempt, CLASS register-only score=3 (see func_00298BA0.md); NOT for src/
#include "common.h"

u8 *func_00298BA0(void *arg0, s32 arg1) {
    s32 count = M2C_FIELD(arg0, s32 *, 0x2C);
    s32 i = 0;

    while (i < count) {
        s32 off = i * 4;
        u8 *base = M2C_FIELD(arg0, u8 **, 0x10);
        u8 *p = off + base;
        if (arg1 == *p) {
            return p;
        }
        i++;
    }
    return NULL;
}
