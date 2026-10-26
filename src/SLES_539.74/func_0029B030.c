// range: 0x29B030 0x29B100
#include "common.h"

struct Data0029B030 {
    char pad[0x20];
    u32 flags;
};

struct Sub0029B030 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    char padD[0x278];
    struct Data0029B030 *data;
};

struct Owner0029B030 {
    char pad[0x590];
};

struct Unit0029B030 {
    char pad0[0x10];
    s16 kind;
    char pad12[0xCE];
    struct Sub0029B030 sub;
};

extern u8 func_0029CAF0(struct Owner0029B030 *owner, struct Unit0029B030 *unit);
extern void func_00292CB0(struct Owner0029B030 *owner, struct Unit0029B030 *unit);
extern s32 func_00296700(struct Owner0029B030 *owner);
extern s32 func_00296870(struct Owner0029B030 *owner);

s32 func_0029B030(struct Owner0029B030 *owner, struct Unit0029B030 *unit)
{
    struct Sub0029B030 *sub;

    sub = &unit->sub;
    if ((unit->sub.data->flags & 0x4000) == 0) {
        return 0;
    }
    if (sub->f8 != 3 || sub->fC != 1) {
        return 0;
    }
    if (func_0029CAF0(owner, unit) == 0) {
        return 0;
    }
    func_00292CB0(owner, unit);
    if (unit->kind == 0 || unit->kind == 1) {
        return func_00296870(owner);
    }
    return func_00296700(owner);
}
