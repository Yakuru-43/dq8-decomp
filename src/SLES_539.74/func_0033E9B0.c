// range: 0x33E9B0 0x33E9E0
#include "common.h"

extern M2C_UNK D_004537E0 __attribute__((section(".data")));
s32 func_0033F4D0(M2C_UNK *, s32);                   /* extern */

s32 func_0033E9B0(s32 arg0)
{
    s32 r = func_0033F4D0(&D_004537E0, arg0);
    if (r != 0) { return *(s32 *)(r + 0x4); }
    return 0;
}
