// range: 0x375900 0x375910
// auto: m2c, verified byte-exact
#include "common.h"

void func_00375900(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
}
