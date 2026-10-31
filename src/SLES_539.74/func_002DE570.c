// range: 0x2DE570 0x2DE5B0
#include "common.h"

extern void func_00131188(char *, s32, s32);
extern void func_00375A80(char *);

void func_002DE570(char *arg0) {
    func_00131188(arg0, 0, 0x84);
    func_00375A80(arg0 + 0x30);
    *(s32 *)(arg0 + 0x70) = 0;
}
