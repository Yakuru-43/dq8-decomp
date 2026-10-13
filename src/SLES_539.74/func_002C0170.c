// range: 0x2C0170 0x2C0180
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00151E10();

int func_002C0170(void * arg0) {
    *(volatile s32 *)((char *)arg0 + 0x100) = 0;
    return func_00151E10(arg0);
}
