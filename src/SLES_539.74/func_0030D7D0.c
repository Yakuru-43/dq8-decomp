// range: 0x30D7D0 0x30D810
#include "common.h"

extern void func_00356930(f32, void *, void *);
extern void *func_0030D180(void *, void *);

void func_0030D7D0(char *arg0) {
    char local[8];

    func_00356930(-100.0f, local, arg0 + 0x168);
    func_0030D180(arg0 + 0x170, local);
}
