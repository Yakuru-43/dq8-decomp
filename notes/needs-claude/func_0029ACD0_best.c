// range: 0x29ACD0 0x29B030
// BEST attempt: CLASS structural score=190 (188 words differ, 844 vs 852).
// 2026-10-27 factory-2: prologue + guards 1-4 now byte-exact through ~+0x11C
// after three fixes (see md "Session 2026-10-27"). Left: slot/sub s-register
// swap, the +038 lw dest, the 6*slot address reassociation, tail block order.
#include "common.h"

struct Data0029ACD0 {
    char pad0;
    u8 b1;
    u8 b2;
    char pad3[9];
    u16 fC;
    char padE;
    u8 kindF;
    char pad10[0x10];
    s32 f20;
};

struct Model0029ACD0 {
    char pad[0x60];
    u8 f60;
    char pad61;
    u16 list[6];
    u8 active[6];
};

struct Sub0029ACD0 {
    s32 state;
    s32 f4;
    s32 f8;
    s32 fC;
    char pad10[0x50];
    s32 f60;
    char pad64[0xC];
    u8 f70;
    char pad71[0x213];
    struct Model0029ACD0 *model;
    struct Data0029ACD0 *data;
};

struct Unit0029ACD0 {
    char pad[0x10];
    s16 slot;
    char pad12[0xCE];
    struct Sub0029ACD0 sub;
};

struct Ai0029ACD0 {
    char pad0[0x3C];
    u8 mode;
    char pad3D[0x4EB];
    u8 flags[36];
};

extern struct Data0029ACD0 *func_001FFBA0(struct Ai0029ACD0 *ai, s32 state);
extern void func_0029BB00(struct Ai0029ACD0 *ai, struct Unit0029ACD0 *unit);
extern u8 func_0029A960(struct Ai0029ACD0 *ai, struct Unit0029ACD0 *unit);
extern u8 func_0029AA30(struct Ai0029ACD0 *ai, struct Unit0029ACD0 *unit);
extern u8 func_0029AC20(struct Ai0029ACD0 *ai, struct Unit0029ACD0 *unit, u8 key);
extern s8 func_0035DE00(struct Unit0029ACD0 *unit);
extern s32 func_0035E590(struct Unit0029ACD0 *unit);
extern s32 func_0035F200(char *name);
extern s32 func_0035F0C0(char *name);
extern char D_00456E30[];

u8 func_0029ACD0(struct Ai0029ACD0 *ai, s32 index, struct Unit0029ACD0 *unit, s32 arg)
{
    s32 slot;
    struct Sub0029ACD0 *sub;
    struct Data0029ACD0 *data;
    s32 bits;

    if (unit == NULL) {
        return 0;
    }
    slot = unit->slot;
    if (unit->sub.model->active[index] != 0) {
        if (ai->flags[6 * slot + index] == 0) {
            return 0;
        }
    }
    unit->sub.state = unit->sub.model->list[index];
    unit->sub.f4 = index;
    sub = &unit->sub;
    if (unit->sub.state < 0) {
        return 0;
    }
    if (unit->sub.state >= 0x2BA) {
        return 0;
    }
    if (unit->sub.state == 0) {
        func_0029BB00(ai, unit);
        return 1;
    }
    data = func_001FFBA0(ai, unit->sub.state);
    sub->data = data;
    sub->f8 = data->b1;
    sub->fC = data->b2;
    if (ai->mode == 2 || sub->f70 == 3) {
        if (data->b1 != 3 && data->kindF != 0x35 && data->kindF != 0x36) {
            return 0;
        }
    }
    bits = data->f20;
    if (sub->state == 0x1A8) {
        bits |= 0x20000000;
    }
    if ((bits & 0x20000000) != 0 || (data->fC > 0 && data->fC < 0x32)) {
        if (sub->f60 >= 2) {
            return 0;
        }
        if (sub->model != NULL && sub->model->f60 == 2) {
            return 0;
        }
    }
    if (arg != 0 && data->kindF == 0x37) {
        return 0;
    }
    if (func_0035DE00(unit) == 1) {
        if (func_0035E590(unit) == 0) {
            if (data->kindF == 0x35 || data->kindF == 0x36) {
                return 0;
            }
        }
    }
    if (func_0035F200(D_00456E30) != 0) {
        if (func_0035F0C0(D_00456E30) != 0) {
            if (data->kindF == 0x35 || data->kindF == 0x36) {
                return 0;
            }
        }
    }
    if (sub->model->f60 != 0) {
        if (sub->model->f60 == 2) {
            if (func_0029A960(ai, unit) == 0) {
                return 0;
            }
        } else if (sub->model->f60 == 1) {
            if (func_0029AA30(ai, unit) == 0) {
                return 0;
            }
        }
    }
    if (func_0029AC20(ai, unit, sub->model->f60) == 0) {
        return 0;
    }
    if (sub->model->active[index] != 0) {
        ai->flags[6 * slot + index] = 0;
    }
    return 1;
}
