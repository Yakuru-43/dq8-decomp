// range: 0x30DBF0 0x30DC30
#include "common.h"

extern void func_00356C20(void *, void *, void *);
extern void *func_0030D180(void *, void *);

void func_0030DBF0(char *arg0) {
    char local[8];

    func_00356C20(local, arg0 + 0x160, arg0 + 0x168);
    func_0030D180(arg0 + 0x170, local);
}
