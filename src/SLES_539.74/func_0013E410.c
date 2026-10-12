// range: 0x13E410 0x13E420
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157B80();

int func_0013E410(void * arg0) {
    return func_00157B80((char *)arg0 + 0x10);
}
