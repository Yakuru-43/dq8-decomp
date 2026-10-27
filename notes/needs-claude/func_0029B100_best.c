// range: 0x29B100 0x29B1A0
#include "common.h"

struct Data0029B100 {
    char pad[1];
    u8 b1;
    u8 b2;
};

struct Sub0029B100 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    char pad10[0x50];
    s32 f60;
    s32 f64;
    char pad68[8];
    u8 mode;
    char pad71[0x217];
    struct Data0029B100 *data;
};

struct Owner0029B100 {
    char pad[0x590];
};

struct Unit0029B100 {
    char pad[0xE0];
    struct Sub0029B100 sub;
};

extern struct Data0029B100 *func_001FFBA0(struct Owner0029B100 *owner,
                                          s32 index);
extern void func_00296B70(struct Owner0029B100 *owner);

s32 func_0029B100(struct Owner0029B100 *owner, struct Unit0029B100 *unit)
{
    struct Sub0029B100 *sub;
    u8 mode;

    sub = &unit->sub;
    mode = sub->mode;
    if (mode == 1) {
        sub->state = 0x21;
        sub->data = func_001FFBA0(owner, sub->state);
        sub->f8 = sub->data->b1;
        sub->fC = sub->data->b2;
        func_00296B70(owner);
        sub->f60 = 0;
        sub->f64 = 1;
        return 1;
    }
    if (mode == 3) {
        return 0;
    }
    switch (mode) {
    default:
        return 0;
    case 2:
        break;
    }
    return 0;
}
