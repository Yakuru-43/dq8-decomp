// range: 0x153770 0x1537A0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00153770(char *arg0, s32 arg1, s32 arg2) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0))) {
        *(s32 *) (M2C_FIELD(arg0, s32 *, 4) + (arg1 * 4)) = arg2;
    }
}
