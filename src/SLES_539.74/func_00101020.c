// range: 0x101020 0x101060
#include "common.h"

struct Call2 {
    s32 target;
    s32 pad0;
    void (*fn)(s32, s32);
};

void func_00101020(struct Call2 *p) {
    s32 target;

    target = p->target;
    if (target == 0) {
        return;
    }
    if (p->fn == 0) {
        return;
    }
    p->fn(target, -1);
}
