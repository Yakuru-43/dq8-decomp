// range: 0x27EB50 0x27EBE0
#include "common.h"

extern void func_0027E200(void *, void *, void *, void *);
extern void func_0027EAA0(void *, void *, void *, void *, void *, void *, void *);

void func_0027EB50(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1)
{
    u8 buf[0x10];

    func_0027E200(buf, a3, t0, t1);
    func_0027EAA0(a0, a1, a2, a3, t0, t1, buf);
}
