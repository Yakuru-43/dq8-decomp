// range: 0x24E480 0x24E4A0
#include "common.h"

extern int func_00252C68();

int func_0024E480(void *arg0) {
    s32 *v = arg0;
    return func_00252C68(v[0], 0x41, v[1], v[2], v[3], v[4]);
}
