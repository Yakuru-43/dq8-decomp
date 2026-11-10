// range: 0x167850 0x167960
#include "common.h"

extern "C" {

extern void *memset(void *, s32, s32);

struct FloatTab {
    f32 f00;   /* 0x00 */
    f32 f04;   /* 0x04 */
    f32 f08;   /* 0x08 */
    f32 f0C;   /* 0x0C */
    f32 f10;   /* 0x10 */
    f32 f14;   /* 0x14 */
    f32 f18;   /* 0x18 */
    f32 f1C;   /* 0x1C */
    f32 f20;   /* 0x20 */
    f32 f24;   /* 0x24 */
    s32 i28;   /* 0x28 */
};

extern FloatTab D_003DD960;
extern FloatTab D_003DD9B0;

union Blk {
    u128 q;
    f32 f[4];
};

struct Unit {
    u8 pad00[0x50];           /* 0x00 */
    Blk v50;                  /* 0x50 */
    Blk v60;                  /* 0x60 */
    s32 i70;                  /* 0x70 */
    u8 pad74[0xC0 - 0x74];
    virtual s32 v0();         /* slot 0x08 */
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 v3();
    virtual s32 v4();
    virtual s32 v5();
    virtual s32 v6();
    virtual s32 v7();
    virtual s32 v8();
    virtual s32 v9();
    virtual s32 v10();
    virtual s32 v11();
    virtual s32 v12();
    virtual s32 v13();
    virtual s32 v14();
    virtual s32 start();      /* slot 0x44 */
    virtual s32 init();       /* slot 0x48 */
    virtual s32 finish();     /* slot 0x4C */
    u8 padC4[0xD0 - 0xC4];
    Blk vD0;                  /* 0xD0 */
    Blk vE0;                  /* 0xE0 */
    Blk vF0;                  /* 0xF0 */
    f32 f100;                 /* 0x100 */
    f32 f104;                 /* 0x104 */
    s32 i108;                 /* 0x108 */
    s32 i10C;                 /* 0x10C */
    s32 i110;                 /* 0x110 */
    u8 pad114[0x120 - 0x114];
    Blk v120;                 /* 0x120 */
    u8 pad130[0x158 - 0x130];
    s32 i158;                 /* 0x158 */
    u8 pad15C[0x184 - 0x15C];
    s32 i184;                 /* 0x184 */
};

struct UnitRaw {
    u8 pad0[0xC0];
    FloatTab *table;          /* 0xC0 */
};

Unit *func_00167850(Unit *unit) {
    FloatTab *tab;
    UnitRaw *raw;

    tab = &D_003DD9B0;
    raw = (UnitRaw *)unit;
    raw->table = &D_003DD960;
    unit->start();
    raw->table = tab;
    unit->i158 = 0;
    unit->i184 = 0;
    unit->init();
    tab->f00 = 100.0f;
    tab->f04 = 160.0f;
    tab->f08 = 18.0f;
    tab->f0C = 10.0f;
    tab->f14 = 40.0f;
    tab->f18 = -150.0f;
    tab->f1C = 20.0f;
    tab->f20 = -150.0f;
    tab->f10 = tab->f20;
    tab->f24 = 25.0f;
    tab->i28 = 0;
    unit->vD0.q = 0;
    unit->vE0.q = 0;
    unit->vF0.q = 0;
    unit->v50.q = 0;
    unit->v60.q = 0;
    unit->v120.q = 0;
    unit->v60.f[2] = 1.0f;
    unit->i70 = 0;
    unit->vF0.f[2] = 1.0f;
    unit->f100 = 8.0f;
    unit->f104 = 2.0f;
    unit->i108 = 1;
    unit->i10C = 1;
    unit->i110 = 0;
    unit->finish();
    return unit;
}

}
