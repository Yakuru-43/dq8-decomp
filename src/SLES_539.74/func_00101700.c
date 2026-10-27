// range: 0x101700 0x101760
#include "common.h"

extern char D_003DD670[];
extern char D_003DD690[];
extern void func_001007A0(void *);

void *func_00101700(char *p, s16 n) {
    if (p != 0) {
        *(char **)p = D_003DD690;
        if (p != 0) {
            *(char **)p = D_003DD670;
        }
        if (n > 0) {
            func_001007A0(p);
        }
    }
    return p;
}
