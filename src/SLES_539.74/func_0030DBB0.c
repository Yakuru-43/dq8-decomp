// range: 0x30DBB0 0x30DBF0
#include "common.h"

extern void func_00356B40(void *, void *, void *);
extern void *func_0030D180(void *, void *);

void func_0030DBB0(char *arg0) {
    char local[8];

    func_00356B40(local, arg0 + 0x160, arg0 + 0x168);
    func_0030D180(arg0 + 0x170, local);
}
