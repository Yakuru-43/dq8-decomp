// range: 0x29BFE0 0x29C140
#include "common.h"

struct Owner0029BFE0 {
    char pad[0x590];
};

struct Unit0029BFE0 {
    char pad[0x10];
    s16 slot;
};

struct Weights0029BFE0 {
    u8 w[6];
};

extern int func_00296850(void *owner);
extern s32 func_00132D38(void);
extern u8 func_0029ACD0(struct Owner0029BFE0 *owner, s32 index, struct Unit0029BFE0 *unit, s32 arg);
extern void func_0029BB00(struct Owner0029BFE0 *owner, struct Unit0029BFE0 *unit);

void func_0029BFE0(struct Owner0029BFE0 *owner, s32 mode, struct Unit0029BFE0 *unit, s32 arg)
{
    u8 *weights;
    s32 i;
    s32 j;
    s32 limit;

    weights = (u8 *)((struct Weights0029BFE0 *)func_00296850(owner) + mode) + 0xCA;
    limit = func_00132D38() % 0x100 + 1;
    i = 0;
    while (i < 6) {
        if (weights[i] >= limit) {
            break;
        }
        limit -= weights[i];
        i++;
    }
    if (i >= 6) {
        i = 5;
    }
    if (func_0029ACD0(owner, i, unit, arg) == 1) {
        return;
    }
    j = i;
    while ((j = j - 1) >= 0) {
        if (func_0029ACD0(owner, j, unit, arg) == 1) {
            return;
        }
    }
    i++;
    for (; i < 6; i++) {
        if (func_0029ACD0(owner, i, unit, arg) == 1) {
            return;
        }
    }
    func_0029BB00(owner, unit);
}
