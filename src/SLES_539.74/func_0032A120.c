// range: 0x32A120 0x32A160
#include "common.h"

extern s32 func_0032A2C0(void *, void *);

s8 func_0032A120(char *arg0) {
    *(s8 *)(arg0 + 0x16) = !func_0032A2C0(arg0 + 0x20, arg0 + 0x78);
    return *(s8 *)(arg0 + 0x16);
}
