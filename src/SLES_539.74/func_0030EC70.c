// range: 0x30EC70 0x30ECB0
#include "common.h"

extern void func_0014DF80(void *);

void func_0030EC70(void **arg0, s32 *arg1) {
    void *p = arg0[1];

    if (p != 0) {
        func_0014DF80(p);
    }
    arg1[0] = 0;
    arg1[1] = 0;
    arg1[2] = 0;
}
