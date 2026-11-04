// range: 0x001619F0 0x00161B30
#include "common.h"

extern char *func_00134750(char *, char *, s32);
extern s32 func_00133F78(char *, char *);
extern s32 func_0012D528(char *);
extern char *D_003A1360[];

s32 func_001619F0(char *spec) {
    char num[4];
    char name[0x1C];
    char *p;
    s8 c;
    s32 len;
    char *q;
    char *dst;
    s32 ndigit;
    s32 i;

    p = spec;
    len = 0;
    while (*p != 0) {
        c = *p;
        if (c == ':') {
            break;
        }
        p++;
        len++;
    }
    if (*p == 0) {
        return -1;
    }
    if (len >= 0x10) {
        return -1;
    }
    func_00134750(name, spec, len);
    name[len] = 0;
    dst = num;
    q = name;
    ndigit = 0;
    while ((c = *q) != 0) {
        if (c >= '0' && c <= '9') {
            ndigit++;
            *dst++ = c;
            *q = 0;
            if (ndigit >= 3) {
                break;
            }
        }
        q++;
    }
    *dst = 0;
    for (i = 0; i < 5; i++) {
        if (func_00133F78(D_003A1360[i], name) == 0) {
            break;
        }
    }
    if (num[0] != 0) {
        func_0012D528(num);
    }
    return i;
}
