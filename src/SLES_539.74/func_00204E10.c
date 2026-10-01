// range: 0x204E10 0x204E20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00204E10(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC);
}
