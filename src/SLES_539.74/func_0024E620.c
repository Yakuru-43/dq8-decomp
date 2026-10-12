// range: 0x24E620 0x24E640
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002529B8();

int func_0024E620(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002529B8(*(s32 *) ((char *) (arg0) + 0x0), 48, 0, *(s32 *) ((char *) (arg0) + 0x4));
}
