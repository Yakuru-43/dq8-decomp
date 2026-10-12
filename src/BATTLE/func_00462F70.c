// range: 0x462F70 0x462F80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_131188();

int func_00462F70(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_131188(arg0, 0, 64, arg3);
}
