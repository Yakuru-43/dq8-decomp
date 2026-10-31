// range: 0x2CD5F0 0x2CD620
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
s32 func_00359CF0(M2C_UNK *, s32);                   /* extern */

s32 func_002CD5F0(s32 arg0)
{
    s32 r = func_00359CF0(&D_00421AD0, arg0);
    if (r != 0) { return *(s32 *)(r + 0x24); }
    return 0;
}
