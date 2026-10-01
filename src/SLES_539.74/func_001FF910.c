// range: 0x1FF910 0x1FF920
// auto: m2c, verified byte-exact
#include "common.h"

void func_001FF910(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x44B8) = (s32) M2C_FIELD(arg0, s32 *, 0x44B4);
    M2C_FIELD(arg0, s32 *, 0x44B4) = arg1;
}
