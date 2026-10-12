// range: 0x1EF130 0x1EF150
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001EA770();

int func_001EF130(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_001EA770(arg1, (char *) (arg0) + 0x1C, (char *) (arg0) + 0x20, arg3);
}
