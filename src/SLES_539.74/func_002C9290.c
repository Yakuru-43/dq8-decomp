// range: 0x2C9290 0x2C92C0
#include "common.h"

extern M2C_UNK D_0044F990 __attribute__((section(".data")));
s32 func_0014E240(M2C_UNK, s32);                     /* extern */
M2C_UNK func_0014DF10(char *, char *, M2C_UNK);      /* extern */

void func_002C9290(M2C_UNK arg0)
{
    s32 r = func_0014E240(arg0, 0x1900);
    func_0014DF10((char *)&D_0044F990, (char *)r, 0x1900);
}
