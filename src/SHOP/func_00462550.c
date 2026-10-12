// range: 0x462550 0x462570
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_004625B0();

int func_00462550(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_004625B0(*(s16 *) ((char *) (*(s32 *) ((char *) (arg0) + 0x18)) + 0x10), *(s16 *) ((char *) (*(s32 *) ((char *) (arg0) + 0x18)) + 0x12), arg1, arg3);
}
