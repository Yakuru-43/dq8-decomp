// range: 0x3722D0 0x372330
#include "common.h"

extern void func_003725D0(char *);

void func_003722D0(char **arg0) {
    s32 i;
    char *p;

    i = 0;
    do {
        p = arg0[i];
        if (p != 0) {
            func_003725D0(p);
        }
        i++;
    } while (i < 6);
}
