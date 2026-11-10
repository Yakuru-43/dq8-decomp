// range: 0x29B3C0 0x29B6C0
// best draft for func_0029B3C0 — NOT matched, do not move into src/
// (see func_0029B3C0.md for the diff state; CLASS structural score=132 this
// version, 127 for the first attempt whose declaration order was
// sub,flags,kind and whose func_00299580 had 10 params and no kind masks)
#include "common.h"

struct Owner0029B3C0 {
    char pad[0x590];
};

struct Data0029B3C0 {
    char pad[1];
    u8 b1;
    u8 b2;
};

struct Sub0029B3C0 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    char pad10[0x208];
    s32 f218;
    char pad21C[0x53];
    u8 b26F;
    char pad270[4];
    s32 f274;
    char pad278[0x10];
    struct Data0029B3C0 *volatile data; // thread-shared: the fetch worker fills it
    char pad28C[4];
    volatile u8 b290; // thread-shared: the worker checks it while busy
};

struct Unit0029B3C0 {
    char pad[0x10];
    s16 slot;
    char pad12[0xB6];
    s16 fC8;
    s16 fCA;
    char padCC[0x14];
    struct Sub0029B3C0 sub;
};

extern s32 func_00296F60(struct Unit0029B3C0 *unit);
extern s32 func_00132D38(void);
extern struct Data0029B3C0 *func_001FFBA0(struct Owner0029B3C0 *owner, s32 index);
extern void func_00292CB0(struct Owner0029B3C0 *owner, struct Unit0029B3C0 *unit);
extern void func_00296BD0(struct Owner0029B3C0 *owner);
extern s32 func_002943C0(struct Owner0029B3C0 *owner);
extern s32 func_00294420(struct Owner0029B3C0 *owner);
extern s32 func_0035DBB0(struct Unit0029B3C0 *unit, s32 arg1, s32 arg2);
extern void func_00299370(struct Owner0029B3C0 *owner, struct Unit0029B3C0 *unit,
                          s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 func_00299580(struct Owner0029B3C0 *owner, struct Unit0029B3C0 *unit,
                         s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                         s32 arg6, s32 arg7, s32 arg8);

s32 func_0029B3C0(struct Owner0029B3C0 *owner, struct Unit0029B3C0 *unit)
{
    s32 flags;
    struct Sub0029B3C0 *sub;
    s32 kind;
    s32 saved354;
    s8 saved370;

    if ((func_00296F60(unit) & 0x40000) == 0) {
        return 0;
    }
    sub = &unit->sub;
    sub->b26F = 1;
    unit->fC8 = -1;
    unit->fCA = -1;
    if (unit->slot == 0 || unit->slot == 1) {
        kind = 1;
    } else {
        kind = 0;
    }
    flags = 0;
    if ((func_00132D38() & 1) == 1) {
        flags = kind & 0xFF;
        if (flags == 1) {
            sub->state = 0x1F;
        } else {
            sub->state = 0x20;
        }
        sub->data = func_001FFBA0(owner, sub->state);
        sub->f8 = sub->data->b1;
        sub->fC = sub->data->b2;
        func_00292CB0(owner, unit);
        if (flags == 1) {
            flags = func_00294420(owner) & 0xFF;
        } else {
            flags = func_002943C0(owner) & 0xFF;
        }
    }
    if ((flags & 0xFF) != 0) {
        return 1;
    }
    if ((kind & 0xFF) == 1) {
        s32 r = func_00132D38() % 4;
        if (r == 3) {
            sub->state = 0x1D1;
        } else if (r == 2) {
            sub->state = 0x1D0;
        } else if (r == 1) {
            sub->state = 0x1CF;
        } else if (r == 0) {
            sub->state = 0x1CE;
        }
    } else {
        s32 r = func_00132D38() % 5;
        if (r == 4) {
            sub->state = 0x1D3;
        } else if (r == 3) {
            sub->state = 0x1D2;
        } else if (r == 2) {
            sub->state = 0x1D1;
        } else if (r == 1) {
            sub->state = 0x1D0;
        } else if (r == 0) {
            sub->state = 0x1CF;
        }
    }
    sub->data = func_001FFBA0(owner, sub->state);
    sub->f8 = sub->data->b1;
    sub->fC = sub->data->b2;
    func_00292CB0(owner, unit);
    func_00296BD0(owner);
    if (sub->state != 0x1D0) {
        return 1;
    }
    if (func_0035DBB0(unit, 1, 1) == 0) {
        goto set_default;
    }
    if (sub->b290 != 0) {
        goto set_default;
    }
    saved354 = sub->f274;
    if (saved354 != 0) {
        goto set_default;
    }
    saved370 = sub->b290;
    func_00299370(owner, unit, 0x12, 0, 0, 0);
    func_00299580(owner, unit, 3, sub->state, sub->f218, 2, 0, 0, 0);
    sub->b290 = saved370;
    sub->f274 = saved354;
    return 1;
set_default:
    sub->state = 0x1CF;
    return 1;
}
