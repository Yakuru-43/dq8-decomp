// range: 0x37BD20 0x37BE00
#include "common.h"

s32 func_00372590(char *);

s32 func_0037BD20(s32 *arg0) {
    s32 count;
    s32 i;
    char *p;
    s32 r;
    s32 flag;

    count = 0;
    for (i = 0; i < 4; i++) {
        p = (char *)arg0[i];
        if (p == NULL) {
            continue;
        }
        if (i < 0 || i >= 4) {
            flag = 1;
        } else {
            if (p != NULL) {
                r = func_00372590(p);
                if (r == 1 || r == -1 || r == 2 || r == 4) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 0) {
            count++;
        }
    }
    return count == 0;
}
