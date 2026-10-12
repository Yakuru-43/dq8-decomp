// range: 0x182620 0x182630
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001F8E50();

int func_00182620(void * arg0, void * arg1) {
    return func_001F8E50(arg0, (void *)0);
}
