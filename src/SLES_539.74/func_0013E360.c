// range: 0x13E360 0x13E380
#include "common.h"

extern void func_00157930(void *, s32);

/* Store the flag value and push it into the node at +0x10. */
void func_0013E360(void *o, s32 v) {
    M2C_FIELD(o, s32 *, 0xE4) = v;
    func_00157930((char *)o + 0x10, M2C_FIELD(o, s32 *, 0xE4));
}
