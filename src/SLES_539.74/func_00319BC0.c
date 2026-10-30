// range: 0x319BC0 0x319C40
#include "common.h"

extern s32 func_00318430(void *, void *, void *);
extern void *func_003296F0(void *);

s32 func_00319BC0(void *arg0, void *arg1, void *arg2, s8 arg3) {
    void *node;
    s8 val;

    val = arg3;
    if (arg1 == 0) {
        return -2;
    }
    node = func_003296F0(arg1);
    if (node == 0) {
        return -1;
    }
    *(s8 *)((char *)node + 4) = val;
    func_00318430(arg0, arg1, arg2);
    return 0;
}
