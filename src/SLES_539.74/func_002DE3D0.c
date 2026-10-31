// range: 0x2DE3D0 0x2DE410
#include "common.h"

s32 func_002DE490(s32, s32);

s16 *func_002DE3D0(s32 arg0) {
    s32 *node;
    node = (s32 *)arg0;
    if (func_002DE490(arg0, 5) != 0) {
        return (s16 *)node[0x2C / 4];
    }
    return 0;
}
