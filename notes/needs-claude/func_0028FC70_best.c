// range: 0x28FC70 0x28FCA0
#include "common.h"

s32 func_0028FC70(void *arg0)
{
    u32 b = *(u8 *)((char *)arg0 + 0x4EC);
    if (b == 2) { return 1; }
    return (b == 3) ? 1 : (b == 6);
}
