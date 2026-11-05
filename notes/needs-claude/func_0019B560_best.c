// best attempt for func_0019B560 (448 B, SLES_539.74) — score=63 structural
// range: 0x19B560 0x19B720
#include "common.h"

extern f32 D_003DF388;
extern f32 D_003DF4B4;
extern f32 D_003DF390;
extern f32 func_00129E60(f32);
extern s32 func_00132D38(void);
extern void func_00131188(char *, s32, s32);

typedef union {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
} Vec16;

typedef struct {
    /* 00 */ s32 active;
    /* 04 */ char pad04[0xC];
    /* 10 */ Vec16 spawn;
} Emitter;

typedef struct {
    /* 00 */ Vec16 pos;
    /* 10 */ f32 f10;
    /* 14 */ s32 counter;
    /* 18 */ s32 count;
    /* 1C */ char pad1C[4];
} Particle;

void func_0019B560(Emitter *arg0) {
    Particle *found;
    Particle *p;
    s32 i;
    s32 step;
    f32 r;

    if (arg0->active == 0) {
        return;
    }
    found = 0;
    for (i = 0; i < 20; i++) {
        p = (Particle *)((char *)arg0 + (i << 5) + 0x90);
        if (p->count <= 0) {
            found = p;
            break;
        }
        if (p->counter < p->count) {
            p->pos.v.y += D_003DF388;
            step = i << 1;
            r = func_00129E60(D_003DF4B4 * ((f32)(p->counter + step) / 10.0f));
            p->pos.v.x = r + 5.0f * r;
            r = func_00129E60(D_003DF4B4 * ((f32)(p->counter + step + 10) / 8.0f));
            p->pos.v.z = r + 5.0f * r;
            p->f10 -= D_003DF390;
            p->counter++;
        } else {
            func_00131188((char *)p, 0, 0x20);
        }
    }
    if (found == 0) {
        return;
    }
    found->pos = arg0->spawn;
    found->f10 = 7.0f;
    found->counter = func_00132D38() % 20;
    found->count = 30;
}
