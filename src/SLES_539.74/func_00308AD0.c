// range: 0x308AD0 0x308B00
// auto: hand
#include "common.h"

struct ValueTable {
    char pad0[0x40];
    u16 values[0x100];
};

s32 func_00308AD0(struct ValueTable *arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 0x100) {
        return -1;
    }
    return arg0->values[arg1];
}
