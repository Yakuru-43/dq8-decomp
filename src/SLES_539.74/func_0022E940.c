// range: 0x22E940 0x22E9E0
#include "common.h"

extern f32 D_003DF390;

typedef struct {                /* 0x60 bytes */
    s128 v0;                    /* 0x00 */
    s128 v1;                    /* 0x10 */
    s128 v2;                    /* 0x20 */
    s32 x30;                    /* 0x30 */
    s32 pad1[3];                /* 0x34 */
    s32 x40;                    /* 0x40 */
    f32 f44;                    /* 0x44 */
    s32 x48;                    /* 0x48 */
    s32 x4C;                    /* 0x4C */
    s32 x50;                    /* 0x50 */
    s32 pad2[3];                /* 0x54 */
} Elem;

typedef struct {
    s128 vec[3];                /* 0x00 */
    Elem elem[3];               /* 0x30 */
    s32 x150[3];                /* 0x150 */
    f32 f15C;                   /* 0x15C */
    s128 z160;                  /* 0x160 */
    s128 z170;                  /* 0x170 */
    s32 x180;                   /* 0x180 */
    f32 f184;                   /* 0x184 */
    s32 pad3[2];                /* 0x188 */
    s32 x190;                   /* 0x190 */
    f32 f194;                   /* 0x194 */
    s32 x198;                   /* 0x198 */
    s32 x19C;                   /* 0x19C */
    f32 f1A0;                   /* 0x1A0 */
} Obj;

void func_0022E940(Obj *o) {
    Elem *e;
    s32 i;
    f32 f;

    f = D_003DF390;
    o->f15C = f;
    o->z160 = 0;
    o->z170 = 0;
    o->x180 = 0;
    o->f184 = 1.0f;
    o->f1A0 = 1.0f;
    o->x190 = 0;
    o->f194 = 1.0f;
    o->x198 = 0;
    o->x19C = 0;
    for (i = 0; i < 3; i++) {
        e = &o->elem[i];
        e->v0 = 0;
        e->v2 = 0;
        e->v1 = 0;
        e->x40 = 0;
        e->f44 = 1.0f;
        e->x48 = 0;
        e->x4C = 0;
        e->x30 = 0;
        e->x50 = 0;
        o->vec[i] = 0;
        o->x150[i] = 0;
    }
}
