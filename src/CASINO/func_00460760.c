// range: 0x460760 0x460770
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_10ADF8();

int func_00460760(void * arg0) {
    return func_10ADF8((char *)arg0 + 0x40);
}
