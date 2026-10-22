// range: 0x100DE0 0x100E60
#include "common.h"

typedef void (*BootFn)(void);

extern void func_00102770(s32 a0, s32 a1);

void func_00100DE0(BootFn *table, BootFn *end, s32 a2, s32 a3) {
    BootFn *p;

    p = table;
    if (p < end) {
        do {
            (*p)();
            p++;
        } while (p < end);
    }
    func_00102770(a2, a3);
}
