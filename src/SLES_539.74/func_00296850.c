// range: 0x296850 0x296860
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00296860();

int func_00296850(void * arg0) {
    return func_00296860(*(s32 *)((char *)arg0 + 0x0));
}
