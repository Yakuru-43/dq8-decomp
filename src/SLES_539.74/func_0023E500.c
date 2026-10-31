// range: 0x23E500 0x23E5C0
#include "common.h"

extern void *D_003E0B24;
extern void func_00151A20(void *obj, f32 *vec);

struct Tagged {
    s32 type;
    union {
        s32 i;
        f32 f;
    } v;
};

struct ScreenArgs {
    struct Tagged index;
    struct Tagged x;
    struct Tagged y;
    struct Tagged z;
};

struct ScreenTable {
    u8 pad[0x10];
    void *entries[1];
};

static inline f32 tagged_get(struct Tagged *t)
{
    return t->type != 0 ? t->v.f : (f32)t->v.i;
}

s32 func_0023E500(struct ScreenArgs *p)
{
    f32 vec[4];
    f32 fx, fy, fz;
    s32 index;
    void **slot;
    struct Tagged *tx, *ty;

    if (p->index.type == 1) {
        index = (s32)p->index.v.f;
    } else {
        index = p->index.v.i;
    }
    slot = (void **)((u32)D_003E0B24 + 0x10 + index * 4);
    if (*slot == 0) {
        return 0;
    }
    tx = &p->x;
    if (p->x.type == 0) {
        fx = (f32)tx->v.i;
    } else {
        fx = tx->v.f;
    }
    vec[0] = fx;
    ty = tx + 1;
    if (tx[1].type == 0) {
        fy = (f32)ty->v.i;
    } else {
        fy = ty->v.f;
    }
    vec[1] = fy;
    fz = tx[2].type == 0 ? (f32)tx[2].v.i : tx[2].v.f;
    vec[2] = fz;
    vec[3] = 1.0f;
    func_00151A20(*slot, vec);
    return 1;
}
