// range: 0x460720 0x460730
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_10ADF8();

int func_00460720(void * arg0) {
    return func_10ADF8((char *)arg0 + 0x40);
}
