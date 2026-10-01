// range: 0x2D3D50 0x2D3D60
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D3D50(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70) != 0;
}
