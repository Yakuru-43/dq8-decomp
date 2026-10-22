// range: 0x1026F0 0x102750
#include "common.h"

u8 *func_00100EE0(u8 *p, u32 *out);

/* Read a flag byte, then three varints; the third only when the 0x40
 * bit of the flag byte is set. Returns the pointer after them. */
u8 *func_001026F0(u8 *p) {
    u32 value;
    u32 flag;

    flag = (s32)*(s8 *)p & 0x40;
    p = func_00100EE0(p + 1, &value);
    p = func_00100EE0(p, &value);
    if (flag != 0) {
        p = func_00100EE0(p, &value);
    }
    return p;
}
