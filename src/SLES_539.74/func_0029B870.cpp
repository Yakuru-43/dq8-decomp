// range: 0x29B870 0x29BAA0
#include "common.h"

struct Cand0029B870 {
    char pad0[0xC];
    s16 type;
    char padE[2];
    s16 busy;
};

struct Node0029B870 {
    char pad0[0x18];
    struct Node0029B870 *next;
    struct Cand0029B870 *data;
};

struct Owner0029B870 {
    char pad0[0x3C];
    u8 mode;
    char pad3D[0x40B];
    struct Node0029B870 head;
};

struct Sub0029B870 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    s32 x;
    s32 y;
    char pad18[0x58];
    u8 kind;
    char pad71[7];
    u64 flags;
    char pad80[0x1F4];
    s32 busy;
    char pad278[0x10];
    void *data;
};

struct Unit0029B870 {
    char pad0[0x10];
    s16 x;
    s16 y;
    char pad14[0xCC];
    struct Sub0029B870 sub;
    u8 locked;
};

extern "C" {

extern f32 D_003DF3BC;

s32 func_0035E590(struct Unit0029B870 *unit);
s32 func_0035DBB0(struct Unit0029B870 *unit, s32 a, s32 b);
s32 func_0029EDB0(struct Owner0029B870 *owner, struct Unit0029B870 *unit, s32 mask);
s32 func_00201760(struct Cand0029B870 *cand, s32 a);
s32 func_0035E580(struct Cand0029B870 *cand);
s32 func_0035E570(struct Cand0029B870 *cand);
f32 func_0035D7F0(struct Cand0029B870 *cand);
f32 func_00297170(f32 lo, f32 hi);
void *func_001FFBA0(struct Owner0029B870 *owner, s32 index);
void func_00299660(struct Owner0029B870 *owner, struct Unit0029B870 *unit, s32 a2, s32 a3,
                   s32 count, struct Cand0029B870 *target, s32 a6, s32 a7, s64 a8, s64 a9);

static inline bool Roll0029B870(f32 roll, f32 rate)
{
    bool ok = false;
    if (roll <= rate) {
        ok = true;
    }
    return ok;
}

bool func_0029B870(struct Owner0029B870 *owner, struct Unit0029B870 *unit)
{
    bool ret = false;

    if (func_0035E590(unit) == 1) {
        bool pass = true;

        if (owner->mode == 2 || unit->sub.kind == 3) {
            pass = false;
        }
        if (func_0035DBB0(unit, 1, 1) == 0 || unit->locked != 0 || unit->sub.busy != 0) {
            pass = false;
        }
        if (unit->sub.flags & 0x20080196) {
            pass = false;
        }
        if (func_0029EDB0(owner, unit, 0x10) >= 3) {
            pass = false;
        }
        if (pass) {
            struct Cand0029B870 *found = NULL;
            struct Node0029B870 *node = &owner->head;

            while ((node = node->next) != NULL) {
                struct Cand0029B870 *cand = node->data;
                if (cand != NULL && cand->busy == 0 && cand->type == 2) {
                    if (func_00201760(cand, 0) > 0 && func_0035E580(cand) == 0 && func_0035E570(cand) == 0) {
                        found = cand;
                    }
                    break;
                }
            }
            if (found != NULL) {
                f32 rate = 256.0f * func_0035D7F0(found);
                if (Roll0029B870(func_00297170(D_003DF3BC, 256.0f), rate)) {
                    struct Sub0029B870 *sub;

                    unit->sub.state = 0;
                    unit->sub.f8 = 1;
                    unit->sub.fC = 1;
                    unit->sub.x = unit->x;
                    unit->sub.y = unit->y;
                    sub = &unit->sub;
                    sub->data = func_001FFBA0(owner, sub->state);
                    func_00299660(owner, unit, 0, 0x15, 0x11, found, 0, 0, 0, 0);
                    ret = true;
                }
            }
        }
    }
    return ret;
}

}
