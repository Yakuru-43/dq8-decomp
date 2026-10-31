// range: 0x319C40 0x319CB0
#include "common.h"

extern s32 func_00318430(void *, void *, void *);
extern void *func_00329600(void *);

s32 func_00319C40(void *arg0, void *arg1, void *arg2) {
    void *node;

    if (arg1 == 0) {
        return -2;
    }
    node = func_00329600(arg1);
    if (node == 0) {
        return -1;
    }
    func_00318430(arg0, arg1, arg2);
    return 0;
}
