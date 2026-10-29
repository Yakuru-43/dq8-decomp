// range: 0x22BD80 0x22BDD0
#include "common.h"

extern void *func_00131188(void *, s32, s32);

void func_0022BD80(void *arg0) {
    s32 *p;

    func_00131188(arg0, 0, 0x30);
    p = (s32 *)arg0;
    p[2] = 0x80;
    *(s8 *)((char *)p + 1) = 1;
    *(f32 *)((char *)p + 0x24) = 1.0f;
    *(s8 *)((char *)p + 0xC) = 0;
}
