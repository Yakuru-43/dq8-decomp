// range: 0x28ED00 0x28ED10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0028DEC0();

int func_0028ED00(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s128 *) ((char *) (arg0) + 0x30) = *(s128 *) ((char *) (arg2) + 0x0);
    return func_0028DEC0(arg0, arg1, arg2, arg3);
}
