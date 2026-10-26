// range: 0x2B0AA0 0x2B0AC0
#include "common.h"

s32 func_002B0AA0(s32 arg0) {
    s32 t = *(s32 *)arg0;

    if (t == 0) {
        return 0;
    }
    return **(s32 **)(arg0 + 8);
}
