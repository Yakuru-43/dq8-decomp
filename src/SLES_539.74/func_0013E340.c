// range: 0x13E340 0x13E350
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157710();

int func_0013E340(void * arg0) {
    return func_00157710((char *)arg0 + 0x10);
}
