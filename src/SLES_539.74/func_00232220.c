// range: 0x232220 0x232260
#include "common.h"

extern int func_00131188(char *buf, s32 flags, s32 size);

int func_00232220(char *arg0) {
    int result;

    result = func_00131188(arg0, 0, 0x7A0);
    arg0[1] = 1;
    return result;
}
