// range: 0x35CA30 0x35CA40
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0035CA40(float);

int func_0035CA30(float arg0) {
    return func_0035CA40(-arg0);
}
