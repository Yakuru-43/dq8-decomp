// range: 0x159620 0x159630
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00158980();

int func_00159620(void * arg0, void * arg1, void * arg2) {
    return func_00158980(arg0, arg1, (void *)0);
}
