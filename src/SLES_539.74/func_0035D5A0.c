// range: 0x35D5A0 0x35D5C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0035E520();

int func_0035D5A0(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s16 *) ((char *) (arg0) + 0xA8) = *(s16 *) ((char *) (arg0) + 0xA6);
    *(s16 *) ((char *) (arg0) + 0xA6) = 0;
    *(s16 *) ((char *) (arg0) + 0xAA) = 0;
    return func_0035E520(arg0, 4096, 2, arg3);
}
