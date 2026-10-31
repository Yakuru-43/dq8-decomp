// range: 0x363410 0x363430
#include "common.h"

void func_00363410(void *arg0) {
    s32 *p = (s32 *)arg0;
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    p[3] = 0x3F800000;
    *(u128 *)((char *)arg0 + 0x10) = *(u128 *)arg0;
}
