// range: 0x326ED0 0x326F40
#include "common.h"

s32 func_0031E440(void *);
M2C_UNK func_00320FE0(s32, s32);
s32 func_00340BC0(s32, s32);

s32 func_00326ED0(void *arg0) {
    void *var_v0;

    var_v0 = *(void **)((char *)arg0 + 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(*(s32 *)((char *)arg0 + 4), func_00340BC0(func_0031E440(*(void **)((char *)*(void **)((char *)var_v0 + 0x2C) + 8)), 1));
    return 0;
}
