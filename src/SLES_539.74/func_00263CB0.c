// range: 0x263CB0 0x263CC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern u8 D_003E0D0C;
extern int func_0037C0F0();

int func_00263CB0(void) {
    D_003E0D0C = 0;
    return func_0037C0F0();
}
