// range: 0x33E980 0x33E9B0
#include "common.h"

extern M2C_UNK D_00453840 __attribute__((section(".data")));
s32 func_0033F450(M2C_UNK *, s32);                   /* extern */

s32 func_0033E980(s32 arg0)
{
    s32 r = func_0033F450(&D_00453840, arg0);
    if (r != 0) { return *(s32 *)(r + 0x4); }
    return 0;
}
