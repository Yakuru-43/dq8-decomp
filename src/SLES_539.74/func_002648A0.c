// range: 0x2648A0 0x2648E0
#include "common.h"

extern int func_00131188(char *buf, s32 flags, s32 size);

char *func_002648A0(char *arg0) {
    char *p;

    p = arg0;
    func_00131188(arg0, 0, 0x30);
    *(s16 *)p = -1;
    *(s16 *)(p + 4) = 0x4B;
    return p;
}
