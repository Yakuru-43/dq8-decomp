// range: 0x24E760 0x24E780
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252868();

int func_0024E760(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252868(5, *(s32 *) ((char *) (arg0) + 0x0), *(s32 *) ((char *) (arg0) + 0x4), arg3);
}
