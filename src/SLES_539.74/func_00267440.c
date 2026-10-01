// range: 0x267440 0x267450
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00267440(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return 2;
}
