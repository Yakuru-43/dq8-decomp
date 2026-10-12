// range: 0x269EE0 0x269EF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00269EF0();

int func_00269EE0(void * arg0, void * arg1, void * arg2) {
    return func_00269EF0(arg0, arg1, (char *)arg1 + 0x40);
}
