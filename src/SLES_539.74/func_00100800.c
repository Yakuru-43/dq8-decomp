// range: 0x100800 0x100850
#include "common.h"

extern char D_003DD670[];
extern void func_001007A0(void);

char *func_00100800(char *p, s16 n) {
    if (p != 0) {
        *(char **)p = D_003DD670;
        if (n > 0) {
            func_001007A0();
        }
    }
    return p;
}
