// range: 0x24E550 0x24E590
#include "common.h"

extern int func_00252C68();

int func_0024E550(void *arg0) {
    s32 *v = arg0;
    return func_00252C68(v[0], 0x13, v[1], v[2], v[3], v[4], v[5], 0, 0.0);
}
