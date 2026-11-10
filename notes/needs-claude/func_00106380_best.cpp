// range: 0x106380 0x106660
// Best factory draft (attempt 1, CLASS structural score=181, 344 vs 724 B);
// see func_00106380.md — the three EH islands are not reproducible in plain C.
#include "common.h"

extern "C" {

struct ObjClass {
    u8 pad00[0x20];
    void *h20;      /* 0x20 handler / secondary object */
    u8 pad24[0x14];
    u16 f38;
    u8 f3A;
    u8 f3B;
    u8 pad3C[4];
    void *f40;
};
struct Obj {
    struct ObjClass *cls;
};
struct Lookup {
    u8 f00;
    u8 flag;
    u8 pad02[2];
    struct Obj *obj;
};
struct Call2 {
    s32 target;
    s32 pad0;
    void (*fn)(s32, s32);
};

extern M2C_UNK D_003BEC20 __attribute__((section(".data")));
extern M2C_UNK D_003BEF90 __attribute__((section(".data")));
extern M2C_UNK D_003DD6B0 __attribute__((section(".data")));
extern void func_001041C0(void *obj);
extern u32 func_001341D8(M2C_UNK *s);
extern s32 func_00100860(s32 n);
extern s32 func_00100970(s32 target);
extern void func_00100780(s32 n);
extern M2C_UNK func_001340C0(void *dst, M2C_UNK *src);
extern M2C_UNK func_00102670(M2C_UNK *a, void *b, void (*cb)(void));
extern void func_00101020(struct Call2 *p);
extern void func_001029C0(void);

struct Lookup *func_00106380(struct Lookup *out, struct Obj *o) {
    struct ObjClass *cls;
    void *next;
    void *slot;
    s32 wait2[2];
    s32 r;
    s32 n;
    s32 p;
    struct Call2 call90;

    out->f00 = 0;
    out->flag = 0;
    out->obj = o;
    cls = out->obj->cls;
    if (cls->f3A != 0) {
        cls->f3A |= 4;
    } else {
        next = cls->f40;
        if (next != 0) {
            func_001041C0(next);
        }
        cls = out->obj->cls;
        if (cls->f3A == 0) {
            out->f00 = 1;
            return out;
        }
        cls->f3A |= 4;
    }
    if (cls->h20 == 0) {
        cls->f3A |= 1;
    }
    if ((u8)(cls->f3A & cls->f3B) == 0) {
        return out;
    }
    slot = &D_003DD6B0;
    r = func_001341D8(&D_003BEC20);
    n = func_00100860(r + 1);
    wait2[0] = n;
    wait2[1] = 0;
    if (n != 0) {
        p = func_00100970(4);
        if (p != 0) {
            *(s32 *)p = 1;
        }
        wait2[1] = p;
        func_00100780(wait2[0]);
        func_00102670(0, 0, 0);
        func_00101020(&call90);
    }
    func_001340C0((void *)wait2[0], &D_003BEC20);
    func_00102670(&D_003BEF90, &slot, func_001029C0);
    return out;
}

}
