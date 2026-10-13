// range: 0x182130 0x182160
#include "common.h"

/* returns the address of a global work area (D_00411A10) as an integer */
extern u32 func_001AE130(void);

void func_00182130(s32 value)
{
    u32 work = func_001AE130();
    if (work != 0) {
        *(s32 *)(work + 0x300) = value;
    }
}
