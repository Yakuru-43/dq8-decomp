// range: 0x29BAB0 0x29BB00
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xE0];
    s32 unkE0;
} S_arg1;

s32 func_0029BAB0(s32 arg0, S_arg1 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1->unkE0;
    if ((temp_v1 != 0xEB) && (temp_v1 != 0xEC) && (temp_v1 != 0x10D) && (temp_v1 != 0x145)) {
        return 0;
    }
    return 1;
}
