// range: 0x29BB00 0x29BB90
#include "common.h"

struct Data0029BB00 {
    char pad[1];
    u8 b1;
    u8 b2;
    char pad3[0xB];
    u8 bE;
};

struct Sub0029BB00 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    char padD[0x278];
    struct Data0029BB00 *data;
    s32 rec;
};

struct Owner0029BB00 {
    char pad[0x590];
};

struct Unit0029BB00 {
    char pad[0xE0];
    struct Sub0029BB00 sub;
};

extern struct Data0029BB00 *func_001FFBA0(struct Owner0029BB00 *owner, s32 index);
extern s32 func_0029A100(struct Owner0029BB00 *owner, s32 index);
extern void func_00292CB0(struct Owner0029BB00 *owner, struct Unit0029BB00 *unit);
extern void func_00296BD0(struct Owner0029BB00 *owner);

void func_0029BB00(struct Owner0029BB00 *owner, struct Unit0029BB00 *unit)
{
    struct Sub0029BB00 *sub;

    unit->sub.state = 0x4C;
    sub = &unit->sub;
    sub->data = func_001FFBA0(owner, unit->sub.state);
    sub->rec = func_0029A100(owner, sub->data->bE);
    sub->f8 = sub->data->b1;
    sub->fC = sub->data->b2;
    func_00292CB0(owner, unit);
    func_00296BD0(owner);
}
