// range: 0x3125A0 0x3125C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();
extern M2C_UNK D_00452A50 __attribute__((section(".data")));

int func_003125A0(void) {
    return func_00131188(&D_00452A50, 0, 16);
}
