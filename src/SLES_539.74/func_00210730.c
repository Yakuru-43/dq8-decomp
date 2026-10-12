// range: 0x210730 0x210740
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00210730(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188((char *) (arg0) + 0x9C8, 0, 20, arg3);
}
