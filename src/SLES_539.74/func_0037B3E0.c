// range: 0x37B3E0 0x37B480
#include "common.h"

s32 func_00372580(char *);

u32 func_0037B3E0(s32 arg0) {
    s32 sum;
    s32 i;
    char *p;
    s32 v;

    sum = 0;
    i = 0;
    if (i < 4) {
        do {
            p = *(char **)(arg0 + (i << 2));
            if (p != 0) {
                if (i >= 0 && i < 4) {
                    if (p != 0) {
                        v = func_00372580(p);
                    } else {
                        v = 0;
                    }
                } else {
                    v = 0;
                }
                sum += v;
            }
            i++;
        } while (i < 4);
    }
    return (u32)sum >> 2;
}
