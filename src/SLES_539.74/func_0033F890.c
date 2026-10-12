// range: 0x33F890 0x33F8A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0033F890(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 40, arg3);
}
