// range: 0x29C320 0x29C560
#include "common.h"

struct Data0029C320 {
    char pad[1];
    u8 b1;
    u8 b2;
};

struct Sub0029C320 {
    s32 fE0;
    char pad4[4];
    s32 f8;
    s32 fC;
    s32 fF0;
    s32 fF4;
    char padF8[0x48];
    s32 f140;
    s32 f144;
    u8 b148;
    char pad149[0x207];
    u8 kind;
    char pad271[0x17];
    struct Data0029C320 *f368;
};

struct Unit0029C320 {
    s32 f0;
    char pad4[8];
    s16 cC;
    char padE[0xBA];
    s16 cC8;
    s16 cCA;
    s16 cCC;
    char padCE[0x12];
    struct Sub0029C320 sub;
};

struct Owner0029C320 {
    char pad[0x448];
    char f448[0x148];
};

struct Out0029C320 {
    s32 f0;
    s32 f4;
    s32 f8;
    char padC[0x10];
    s32 f1C;
    s32 f20;
    char pad24[0xC];
};

struct Params0029C320 {
    s32 f0;
    s32 f4;
    char pad8[0x628];
};

struct Sel0029C320 {
    char pad[0x30];
};

struct Large0029C320 {
    char pad[0xD40];
};

struct Name0029C320 {
    char pad[0x60];
};

extern s32 func_0035DBB0(struct Unit0029C320 *unit, s32 a, s32 b);
extern void func_0029C640(struct Large0029C320 *large);
extern void func_0014E8A0(struct Name0029C320 *name);
extern void func_0018DCB0(struct Name0029C320 *name, char *buf, s32 size);
extern void func_0029C5D0(struct Out0029C320 *out);
extern void func_002022C0(s32 id, struct Params0029C320 *params, u8 kind, s32 flag);
extern void func_0030F480(struct Large0029C320 *large, struct Name0029C320 *name, void *data, struct Params0029C320 *params);
extern void func_0030F250(struct Sel0029C320 *sel, struct Large0029C320 *large, struct Unit0029C320 *unit);
extern void func_0029C560(struct Out0029C320 *out, struct Sel0029C320 *sel);
extern f32 func_0035E8B0(void);
extern s32 func_00296F10(struct Unit0029C320 *unit);
extern struct Data0029C320 *func_001FFBA0(struct Owner0029C320 *owner, s32 index);
extern void func_00300CB0(s32 a, const char *file, s32 line);
extern const char D_003CBEA0[];

void func_0029C320(struct Owner0029C320 *owner, struct Unit0029C320 *unit)
{
    struct Large0029C320 large;
    struct Name0029C320 name;
    char buf[0x10000];
    struct Out0029C320 out;
    struct Params0029C320 params;
    struct Sel0029C320 sel;
    struct Sub0029C320 *sub;

    if (func_0035DBB0(unit, 0, 0) == 0) {
        return;
    }
    func_0029C640(&large);
    func_0014E8A0(&name);
    func_0018DCB0(&name, buf, 0x1000);
    sub = &unit->sub;
    func_0029C5D0(&out);
    func_002022C0(unit->cC, &params, unit->sub.kind, 1);
    func_0030F480(&large, &name, owner->f448, &params);
    func_0030F250(&sel, &large, unit);
    func_0029C560(&out, &sel);
    if (out.f0 < 0) {
        out.f4 = -1;
        out.f8 = -1;
        switch (unit->sub.kind) {
        case 0:
        case 3:
        case 2:
        case 4:
            out.f0 = params.f4;
            break;
        case 1:
            out.f0 = 0x106;
            if (func_0035E8B0() <= func_00296F10(unit)) {
                out.f0 = params.f4;
            }
            break;
        default:
            func_00300CB0(0, D_003CBEA0, 0xD45);
            return;
        }
    }
    sub->fE0 = out.f0;
    sub->fF0 = out.f4;
    sub->fF4 = out.f8;
    sub->f368 = func_001FFBA0(owner, sub->fE0);
    if (sub->f368 != 0) {
        sub->f8 = sub->f368->b1;
        sub->fC = sub->f368->b2;
    }
    sub->f140 = 0;
    sub->f144 = 1;
    sub->b148 = 0;
    if (out.f1C != 0) {
        unit->cC8 = out.f1C;
        unit->cCA = unit->f0 - 1000;
        unit->cCC = out.f20;
    }
}
