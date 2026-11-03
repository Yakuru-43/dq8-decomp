// range: 0x460330 0x4606D0
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    f32 v[16];
} Floats16;

typedef struct {
    u128 v[12];
} Quads12;

typedef struct {
    s32 d[32];
} Block80;

typedef struct {
    s32 unk0;
    s32 unk4;
    Vec4 vec __attribute__((aligned(16))); /* 0x10 */
    s32 arr1[16];                          /* 0x20 */
    s32 arr2[16];                          /* 0x60 */
    Floats16 f;                            /* 0xA0 */
    Quads12 q;                             /* 0xE0 */
} State;

struct Obj;

typedef struct Vtbl {
    u32 slot0[6];
    void (*slot18)(struct Obj *, f32); /* 0x18 */
    u32 slot1C[2];
    void (*slot24)(struct Obj *); /* 0x24 */
} Vtbl;

typedef struct Obj {
    u8 pad0[0x1B0];
    Vtbl *vtbl; /* 0x1B0 */
} Obj;

typedef struct {
    Obj *unk0;
    char *unk4;
    char *unk8;
    s32 unkC;
} Arg;

extern char *func_15F490(void);
extern void func_1487A0(char *);
extern void func_14FFA0(char *, char *);
extern State D_0047F430[];

void func_00460330(Arg *arg0) {
    char *handle;
    State *obj;
    State save;
    s32 *walk_src;
    s32 *walk_dst;
    u128 *quad_src;
    u128 *quad_dst;
    s32 idx;
    s32 i;
    char *preset;
    char *p;

    handle = func_15F490();
    obj = *(State **)(handle + 0x36B0);
    save.unk0 = obj->unk0;
    save.unk4 = obj->unk4;
    save.vec = obj->vec;
    walk_src = obj->arr1;
    walk_dst = save.arr1;
    i = 8;
    do {
        *walk_dst++ = *walk_src++;
        *walk_dst++ = *walk_src++;
        i--;
    } while (i > 0);
    walk_src = obj->arr2;
    walk_dst = save.arr2;
    i = 8;
    do {
        *walk_dst++ = *walk_src++;
        *walk_dst++ = *walk_src++;
        i--;
    } while (i > 0);
    save.f = obj->f;
    quad_src = obj->q.v;
    quad_dst = save.q.v;
    i = 6;
    do {
        *quad_dst++ = *quad_src++;
        *quad_dst++ = *quad_src++;
        i--;
    } while (i > 0);
    idx = arg0->unkC;
    if (idx != -1) {
        if (idx < 4) {
            preset = (char *)&D_0047F430[idx] + 0x1C0;
            *(Block80 *)((char *)obj + 0x20) = *(Block80 *)(preset + 0x20);
            *(u128 *)((char *)obj + 0x10) = *(u128 *)(preset + 0x10);
        }
    }
    func_1487A0(handle);
    if (arg0->unk8 != 0) {
        p = arg0->unk4;
        if (p != 0) {
            func_14FFA0(handle, p + 0x120);
        }
    }
    if (arg0->unk0 != 0) {
        arg0->unk0->vtbl->slot18(arg0->unk0, 1.0f);
        arg0->unk0->vtbl->slot24(arg0->unk0);
    }
    obj->unk0 = save.unk0;
    obj->unk4 = save.unk4;
    obj->vec = save.vec;
    walk_src = save.arr1;
    walk_dst = obj->arr1;
    i = 8;
    do {
        *walk_dst++ = *walk_src++;
        *walk_dst++ = *walk_src++;
        i--;
    } while (i > 0);
    walk_src = save.arr2;
    walk_dst = obj->arr2;
    i = 8;
    do {
        *walk_dst++ = *walk_src++;
        *walk_dst++ = *walk_src++;
        i--;
    } while (i > 0);
    obj->f = save.f;
    quad_src = save.q.v;
    quad_dst = obj->q.v;
    i = 6;
    do {
        *quad_dst++ = *quad_src++;
        *quad_dst++ = *quad_src++;
        i--;
    } while (i > 0);
    func_1487A0(handle);
}
