// range: 0x29D5C0 0x29D750
#include "common.h"

struct Kind0029D5C0 {
    char pad[0x60];
    u8 b60;
};

struct Data0029D5C0 {
    char pad[0xE];
    u8 bE;
};

struct Target0029D5C0 {
    char pad0[0xE0];
    s32 fE0;
    s32 fE4;
    s32 fE8;
    s32 fEC;
    s32 fF0;
    s32 pool[19];
    s32 f140;
    s32 f144;
    u8 b148;
    char pad149[0x21B];
    struct Kind0029D5C0 *f364;
    struct Data0029D5C0 *f368;
    s32 f36C;
};

extern void func_0035B1B0(void *arg0);
extern void func_0035B0B0(void *arg0);
extern void func_0029C140(void *owner, struct Target0029D5C0 *target, s32 idx, s32 arg3);
extern struct Data0029D5C0 *func_001FFBA0(void *owner, s32 index);
extern s32 func_0029A100(void *owner, s32 index);
extern void func_0029E150(void *owner, struct Target0029D5C0 *target);
extern char D_00421AD0 __attribute__((section(".data")));

void func_0029D5C0(void *owner, struct Target0029D5C0 *target, s32 arg2)
{
    struct Kind0029D5C0 *kind;
    s32 saved;
    s32 idx;

    if (target == 0) {
        return;
    }
    kind = target->f364;
    if (kind == 0) {
        return;
    }
    if (kind->b60 == 2) {
        target->b148 = 1;
        return;
    }
    saved = target->f140;
    func_0035B1B0(&D_00421AD0);
    idx = saved;
    while (idx <= target->f144) {
        target->f140 = idx;
        func_0029C140(owner, target, idx, arg2);
        idx = idx + 1;
    }
    func_0035B0B0(&D_00421AD0);
    target->f140 = saved;
    target->b148 = 1;
    target->fE0 = target->pool[target->f140];
    target->fE4 = target->pool[target->f140 + 3];
    target->fE8 = target->pool[target->f140 + 6];
    target->fEC = target->pool[target->f140 + 9];
    target->fF0 = target->pool[target->f140 + 12];
    target->pool[0] = target->pool[target->f140 + 15];
    target->f368 = func_001FFBA0(owner, target->fE0);
    if (target->f368 == 0) {
        target->f36C = 0;
    } else {
        target->f36C = func_0029A100(owner, target->f368->bE);
    }
    func_0029E150(owner, target);
}
