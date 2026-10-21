// range: 0x460710 0x460720
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_10ADF8();

int func_00460710(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_10ADF8(arg1, (char *) (arg0) + 0x40, arg2, arg3);
}
