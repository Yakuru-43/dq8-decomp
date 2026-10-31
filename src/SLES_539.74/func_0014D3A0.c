// range: 0x14D3A0 0x14D410
#include "common.h"

extern void func_0013B790(f32, s128 *);

void func_0014D3A0(char **arg0, s128 *arg1) {
    char *p;
    s32 val;

    p = *arg0;
    if (p == NULL) {
        return;
    }
    *arg1 = *(s128 *)(p + 0x20);
    p = *arg0;
    if (p != NULL) {
        val = *(u8 *)(p + 0x10);
    } else {
        val = 0x20;
    }
    if (val == 8) {
        func_0013B790(256.0f, arg1);
    }
}
