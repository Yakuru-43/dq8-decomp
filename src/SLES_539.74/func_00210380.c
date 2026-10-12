// range: 0x210380 0x210390
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00210380(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188((char *) (arg0) + 0x6BF0, 0, 2400, arg3);
}
