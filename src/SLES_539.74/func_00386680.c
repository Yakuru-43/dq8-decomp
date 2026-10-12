// range: 0x386680 0x3866A0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00386680(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *) (arg0 + (arg1 * 0x10) + (arg2 * 4)) = arg3;
}
