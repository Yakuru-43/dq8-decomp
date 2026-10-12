// range: 0x24E720 0x24E740
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252570();

int func_0024E720(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252570(5, *(s32 *) ((char *) (arg0) + 0x0), *(s32 *) ((char *) (arg0) + 0x4), *(s32 *) ((char *) (arg0) + 0x8));
}
