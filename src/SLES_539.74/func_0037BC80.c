// range: 0x37BC80 0x37BD20
#include "common.h"

s32 func_00372590(char *);

s32 func_0037BC80(s32 *arg0) {
    s32 count;
    s32 i;
    char *p;
    s32 r;

    count = 0;
    for (i = 0; i < 4; i++) {
        p = (char *)arg0[i];
        if (p == NULL) {
            continue;
        }
        if (i >= 0 && i < 4) {
            if (p != NULL) {
                r = func_00372590(p);
            } else {
                r = -2;
            }
        } else {
            r = -2;
        }
        if (r != 0) {
            count++;
        }
    }
    return count == 0;
}
