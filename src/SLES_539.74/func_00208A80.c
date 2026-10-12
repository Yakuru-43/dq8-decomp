// range: 0x208A80 0x208A90
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00372B30();

int func_00208A80(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00372B30((char *) (arg0) + 0x5790, 2, arg2, arg3);
}
