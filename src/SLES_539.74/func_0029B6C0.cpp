// range: 0x29B6C0 0x29B870
#include "common.h"

struct Chance0029B6C0 {
    f32 prob;
    u8 count;
};

struct Sub0029B6C0 {
    s32 state;
    char pad4[4];
    s32 f8;
    s32 fC;
    s32 x;
    s32 y;
    char pad18[0x48];
    s32 f60;
    s32 f64;
    char pad68[0x20C];
    s32 busy;
    char pad278[0x10];
    void *data;
};

struct Owner0029B6C0 {
    char pad[0x590];
};

struct Unit0029B6C0 {
    char pad0[0x10];
    s16 x;
    s16 y;
    char pad14[0xCC];
    struct Sub0029B6C0 sub;
    char pad36C[4];
    u8 locked;
};

extern "C" {

s32 func_0035E590(struct Unit0029B6C0 *unit);
s32 func_0035DBB0(struct Unit0029B6C0 *unit, s32 a, s32 b);
s32 func_0035BD10(struct Unit0029B6C0 *unit, s32 slot);
s32 func_00259D70(s32 idx, struct Chance0029B6C0 *out);
s32 func_00132D38(void);
s64 func_0035E320(struct Unit0029B6C0 *unit);
void func_00299660(struct Owner0029B6C0 *owner, struct Unit0029B6C0 *unit, s32 a2, s32 a3,
                   s32 count, struct Unit0029B6C0 *target, s32 a6, s32 a7, s64 a8, s64 a9);
void *func_001FFBA0(struct Owner0029B6C0 *owner, s32 index);

bool func_0029B6C0(struct Owner0029B6C0 *owner, struct Unit0029B6C0 *unit)
{
    bool ret = false;

    if (func_0035E590(unit) == 0) {
        if (func_0035DBB0(unit, 1, 1) != 0) {
            if (unit->locked == 0 && unit->sub.busy == 0) {
                s32 i;
                for (i = 0; i < 5; i++) {
                    struct Chance0029B6C0 chance;
                    s32 idx =func_0035BD10(unit, i);
                    if (idx >= 0 && func_00259D70(idx, &chance) != 0) {
                        s32 weight = (s32)(256.0f * chance.prob);
                        if (func_00132D38() % 256 < weight) {
                            s32 saved = (s32)func_0035E320(unit);
                            func_00299660(owner, unit, 0, 0x15, chance.count, unit, 2, 0, 0, 0);
                            if (saved != (s32)func_0035E320(unit)) {
                                struct Sub0029B6C0 *sub;

                                unit->sub.state = 0;
                                unit->sub.f8 = 1;
                                unit->sub.fC = 1;
                                unit->sub.x = unit->x;
                                unit->sub.y = unit->y;
                                unit->sub.f60 = 0;
                                unit->sub.f64 = 0;
                                sub = &unit->sub;
                                sub->data = func_001FFBA0(owner, sub->state);
                                ret = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

}
