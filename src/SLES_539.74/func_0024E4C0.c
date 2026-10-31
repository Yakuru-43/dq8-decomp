// range: 0x24E4C0 0x24E4E0
#include "common.h"

extern int func_00252C68();

int func_0024E4C0(void *arg0) {
    s32 *v = arg0;
    return func_00252C68(v[0], 0x42, v[1], v[2], v[3], v[4]);
}
