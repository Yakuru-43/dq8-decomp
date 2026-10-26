// range: 0x24E780 0x24E7A0
#include "common.h"

extern int func_00252570();

int func_0024E780(void *arg0) {
    s32 *v = arg0;
    return func_00252570(3, v[0], v[1], v[2], v[3], v[4]);
}
