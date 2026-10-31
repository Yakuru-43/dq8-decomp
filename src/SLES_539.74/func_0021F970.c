// range: 0x21F970 0x21F9A0
// auto: m2c, verified byte-exact
#include "common.h"

extern void func_002E4DC0(void *arg0, s16 arg1, s16 arg2);

void func_0021F970(void *arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        func_002E4DC0(arg0, (s16) arg1, (s16) arg2);
    }
}
