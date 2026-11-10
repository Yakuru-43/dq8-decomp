// range: 0x26DDA0 0x26DDD0
#include "common.h"

extern s32 func_00268230(s32, s32);

s32 func_0026DDA0(s32 arg0, s32 arg1, s32 arg2) {
    s32 obj = *(s32 *)arg2;
    s32 link = *(s32 *)(obj + 0x54);

    if (link == 0) {
        return 0;
    }
    func_00268230(link, *(s32 *)(obj + 0x20));
    return 1;
}
