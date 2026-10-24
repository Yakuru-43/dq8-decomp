// range: 0x308B50 0x308B80
// auto: hand
#include "common.h"

struct ValueTable {
    char pad0[0x10];
    u16 values[0x18];
};

s32 func_00308B50(struct ValueTable *arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 0x18) {
        return -1;
    }
    return arg0->values[arg1];
}
