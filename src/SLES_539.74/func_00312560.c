// range: 0x312560 0x312580
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00220080();
extern M2C_UNK D_00415A40 __attribute__((section(".data")));

int func_00312560(void *arg0, void *arg1) {
    return func_00220080(&D_00415A40, arg0, arg1, -1);
}
