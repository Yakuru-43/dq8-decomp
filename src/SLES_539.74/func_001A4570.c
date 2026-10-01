// range: 0x1A4570 0x1A45E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A4570(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 8) == 0) && (M2C_FIELD(arg0, s32 *, 0x10) == 0) && (M2C_FIELD(arg0, s32 *, 0x18) == 0) && (M2C_FIELD(arg0, s32 *, 0x20) == 0) && (M2C_FIELD(arg0, s32 *, 0x28) == 0) && (M2C_FIELD(arg0, s32 *, 0x30) == 0) && (M2C_FIELD(arg0, s32 *, 0x38) == 0)) {
        return 1;
    }
    return 0;
}
