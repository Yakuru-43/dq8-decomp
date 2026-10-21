// range: 0x100900 0x100960
#include "common.h"

extern char D_003DD670[];
extern char D_003DD680[];
extern void func_001007A0(void *);

void *func_00100900(char *p, s16 n) {
    if (p != 0) {
        *(char **)p = D_003DD680;
        if (p != 0) {
            *(char **)p = D_003DD670;
        }
        if (n > 0) {
            func_001007A0(p);
        }
    }
    return p;
}
