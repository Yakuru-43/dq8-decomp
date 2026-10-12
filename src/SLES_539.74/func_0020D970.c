// range: 0x20D970 0x20D980
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00130FD0();

int func_0020D970(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00130FD0((char *) (arg0) + 0x66E0, arg1, 8, arg3);
}
