// range: 0x35D520 0x35D530
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0035D3B0();

int func_0035D520(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0035D3B0(arg0, *(s16 *) ((char *) (arg0) + 0xA6), *(s16 *) ((char *) (arg0) + 0xA8), arg3);
}
