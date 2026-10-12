// range: 0x208C10 0x208C20
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00305A40();

int func_00208C10(void * arg0) {
    return func_00305A40((char *)arg0 + 0x655C);
}
