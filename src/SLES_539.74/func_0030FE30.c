// range: 0x30FE30 0x30FE50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00310050();

int func_0030FE30(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00310050(arg0, 4, arg1, arg2);
}
