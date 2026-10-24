// range: 0x3083C0 0x308460
// auto: hand, verified byte-exact
#include "common.h"

struct StatTable {
    char pad[0x150];
    s16 values[0x80];
};

s32 func_003083C0(struct StatTable *arg0, s32 arg1, s32 arg2) {
    s16 value;
    s32 sum;

    if (arg1 < 0 || arg1 >= 0x80) {
        return 0;
    }
    if (arg1 >= 0 && arg1 < 0x80) {
        value = arg0->values[arg1];
    } else {
        value = 0;
    }
    sum = arg2 + value;
    if (sum < 0) {
        sum = 0;
    }
    if (sum >= 0x7FFF) {
        sum = 0x7FFF;
    }
    if (arg1 >= 0 && arg1 < 0x80) {
        arg0->values[arg1] = (s16)sum;
    }
    return (s16)sum;
}
