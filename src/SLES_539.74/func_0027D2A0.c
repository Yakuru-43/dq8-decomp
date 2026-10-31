// range: 0x27D2A0 0x27D310
#include "common.h"

extern void func_0027E200(void *, void *, void *, void *);
extern void func_0027D310(void *, void *, void *, void *, void *);

void func_0027D2A0(void *a0, void *a1, void *a2, void *a3) {
    u8 buf[0x10];

    func_0027E200(buf, a1, a2, a3);
    func_0027D310(a0, a1, a2, a3, buf);
}
