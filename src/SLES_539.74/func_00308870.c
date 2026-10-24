// range: 0x308870 0x3088A0
// auto: hand
#include "common.h"

struct ValueTable {
    char pad0[0x540];
    u16 values[0x20];
};

s32 func_00308870(struct ValueTable *arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 0x20) {
        return -1;
    }
    return arg0->values[arg1];
}
