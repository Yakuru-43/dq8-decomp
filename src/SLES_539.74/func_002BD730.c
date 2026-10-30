// range: 0x2BD730 0x2BD790
#include "common.h"

extern char *func_0016D5B0(char *, s32);
extern void func_002BD790(char *, s32);

void func_002BD730(char *arg0) {
    s32 i;
    char *p;

    i = 0;
    do {
        p = func_0016D5B0(arg0, i);
        if (p != 0) {
            func_002BD790(p, -1);
        }
        i++;
    } while (i < 4);
}
