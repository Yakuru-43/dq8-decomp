// range: 0x15B3F0 0x15B580
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Ent15B3F0;

typedef struct {
    u8 pad[104];
} Rec104;

typedef struct {
    s32 a;
    s32 b;
} Rec8;

typedef struct {
    s32 x00;
    s32 x04;
    s32 x08;
    s32 x0C;
    s32 x10;
    s32 x14;
    u8 x18;
    Ent15B3F0 *x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
    s32 x30[101];
    Rec104 *x1C4;
    Rec104 **x1C8;
    s32 x1CC;
    s32 x1D0;
    Rec8 *x1D4;
    Rec8 **x1D8;
    s32 x1DC;
    s32 x1E0;
    u8 x1E4;
    s32 x1E8;
    s32 x1EC;
    s32 x1F0;
    s32 x1F4;
} Obj15B3F0;

void DebugPrintf(const char *fmt, ...);
extern char D_003C2168[];

void func_0015B3F0(Obj15B3F0 *o, s32 arg1, s32 arg2) {
    s32 i;

    o->x00 = arg1;
    o->x04 = arg2;
    if (o->x04 < 0) {
        o->x04 = 0x3FE0;
    }
    o->x14 = 0;
    o->x10 = 0;
    o->x18 = 0;
    if (o->x1C == NULL) {
        return;
    }
    for (i = 0; i < o->x0C; i++) {
        Ent15B3F0 *e = &o->x1C[i];
        e->b = 0;
        e->a = 0;
        e->d = 0;
        e->c = 0;
    }
    o->x24 = 0;
    o->x20 = 0;
    o->x2C = 0;
    o->x28 = 0;
    for (i = 0; i < o->x1CC; i++) {
        o->x1C8[i] = &o->x1C4[i];
    }
    o->x1D0 = 0;
    for (i = 0; i < o->x0C; i++) {
        o->x1C[i].a = o->x00;
        o->x1C[i].b = o->x00;
    }
    o->x08 = -1;
    o->x1E4 = 0;
    for (i = 0; i < 101; i++) {
        o->x30[i] = 0;
    }
    for (i = 0; i < o->x1DC; i++) {
        o->x1D8[i] = &o->x1D4[i];
    }
    o->x1E0 = 0;
    o->x1F4 = 0;
    DebugPrintf(D_003C2168, arg1, arg2);
}
