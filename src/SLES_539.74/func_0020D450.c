// range: 0x20D450 0x20D4D0
#include "common.h"

s32 func_0014E240(void *, s32);                      /* extern */

void func_0020D450(void *arg0, void *arg1) {
    char *obj;
    char *pool;

    obj = arg0;
    pool = arg1;
    if (pool == 0) {
        M2C_FIELD(obj, s32 *, 0x64F4) = 0;
        M2C_FIELD(obj, s32 *, 0x647C) = 0;
        M2C_FIELD(obj, s32 *, 0x6418) = 0;
    } else {
        M2C_FIELD(obj, s32 *, 0x64F4) = func_0014E240(pool, 0x200);
        M2C_FIELD(obj, s32 *, 0x647C) = func_0014E240(pool, 0x38C);
        M2C_FIELD(obj, s32 *, 0x6418) = func_0014E240(pool, 0x180);
    }
}
