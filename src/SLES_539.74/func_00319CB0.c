// range: 0x319CB0 0x319D40
#include "common.h"

extern s32 func_00318430(void *, void *, void *);
extern void *func_00329880(void *);

s32 func_00319CB0(void *arg0, void *arg1, void *arg2, s32 arg3) {
    void *node;
    s32 val;

    val = arg3;
    if (arg1 == 0) {
        return -2;
    }
    node = func_00329880(arg1);
    if (node == 0) {
        return -1;
    }
    *(s32 *)((char *)node + 4) = 3;
    *(s8 *)((char *)node + 8) = 0;
    *(s32 *)((char *)node + 0x38) = val;
    func_00318430(arg0, arg1, arg2);
    return 0;
}
