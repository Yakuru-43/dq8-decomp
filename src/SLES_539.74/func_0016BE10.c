// range: 0x16BE10 0x16BEF0
#include "common.h"

extern char *func_0014E130(char *, s32);
extern void func_0014DF10(char *, char *, s32);

s32 func_0016BE10(char *arg0, s32 arg1, s32 arg2) {
    char *p;
    char *q;
    char *r;

    if ((arg1 >= 0) && (arg1 < 14)) {
        p = arg0 + (arg1 * 0x58) + 0x38;
    } else {
        p = NULL;
    }
    q = arg0 + 0x38;
    if (*(s32 *)(arg0 + 0x508) != 0) {
        return -1;
    }
    if ((p == NULL) || (q == NULL)) {
        return -1;
    }
    r = func_0014E130(q, arg2);
    if (r == NULL) {
        return -1;
    }
    *(s32 *)(arg0 + (arg1 << 2)) = -1;
    func_0014DF10(p, r, arg2);
    return 0;
}
