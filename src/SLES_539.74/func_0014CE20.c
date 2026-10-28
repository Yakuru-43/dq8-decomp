// range: 0x14CE20 0x14CF00
#include "common.h"

s32 func_0014CE20(char *arg0, char *arg1) {
    char *s;
    char *t;
    s32 n;
    s32 m;
    s8 c;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    s = arg0;
    t = arg1;
    n = 0;
    m = 0;
    while ((c = *s) != 0) {
        if (c == '-' && *(s + 1) == '-') {
            break;
        }
        n++;
        s++;
    }
    while ((c = *t) != 0) {
        if (c == '-' && *(t + 1) == '-') {
            break;
        }
        m++;
        t++;
    }
    if (n != m) {
        return 0;
    }
    m = 0;
    while (m < n) {
        if (*arg0 != *arg1) {
            return 0;
        }
        arg0++;
        arg1++;
        m++;
    }
    return 1;
}
