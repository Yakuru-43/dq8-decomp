// range: 0x104440 0x104610
// Twin of func_001041C0 (notes/needs-claude/func_001041C0.md): recursive
// object step, prologue lookup via func_00106660, virtual poll, scheduler wait.
// factory-1 session 2026-10-26, best draft: size exact (464 B with throw(),
// 476 B with the narrow-local tail below); tail checks +110..+13C match the
// original word-for-word. See the .md for the remaining walls.
// Test: .venv/bin/python tools/try_match.py <file> func_00104440 0x104440 --ver 3.0.1b151-050317 -- -O3
#include "common.h"

extern "C" {
struct ObjClass;
struct Handler {                      // cls->[0x20]: 7 virtuals, call +0x18
    virtual s32 v_0x00(); virtual s32 v_0x04(); virtual s32 v_0x08();
    virtual s32 v_0x0C(); virtual s32 v_0x10(); virtual s32 v_0x14();
    virtual s32 v_0x18();
};
struct Obj { struct ObjClass *cls; };
struct ObjClass {
    u8 pad00[0x20]; struct Handler *h20; u8 pad24[0x14];
    u16 f38; u8 f3A; u8 f3B;
};
struct Lookup { u8 f00; u8 flag; u8 pad02[2]; struct Obj *obj; };
struct Call2 { s32 target; s32 pad0; void (*fn)(s32, s32); };

extern M2C_UNK D_003BEC20 __attribute__((section(".data")));
extern M2C_UNK D_003BEF90 __attribute__((section(".data")));
extern M2C_UNK D_003DD6B0 __attribute__((section(".data")));
extern void func_00106660(struct Lookup *out, struct Obj *o);
extern u32 func_001341D8(M2C_UNK *s);
extern s32 func_00100860(s32 n);
extern void func_00102C10(void *slot, s32 n);
extern M2C_UNK func_001340C0(void *dst, M2C_UNK *src);
extern M2C_UNK func_00102670(M2C_UNK *a, void *b, void (*cb)(void));
extern void func_00101020(struct Call2 *p);
extern void func_001029C0(void);

struct Obj *func_00104440(struct Obj *o) throw() {
    struct Call2 call60;
    void *slot78; void *slot7C;
    struct Lookup lookup;
    s32 cancelled, r, n; u8 *flagp; u8 m; u16 w;
    struct ObjClass *cls; struct Handler *h; struct Obj *q;

    func_00106660(&lookup, o);
    flagp = &lookup.flag;
    *flagp = 1;
    h = o->cls->h20;
    if (h == 0) { goto tail; }
    cancelled = 0;
    r = h->v_0x18();
    if (r == -1) { cancelled = 1; }
loop_head:
    if (cancelled == 0) { goto tail; }
    cls = o->cls;
    cls->f3A |= 1;
    if (cls->h20 == 0) { cls->f3A |= 1; }
    m = cls->f3A & cls->f3B;
    if (m == 0) { goto tail; }
    slot78 = &D_003DD6B0;
    r = func_001341D8(&D_003BEC20);
    n = func_00100860(r + 1);
    func_00102C10(&slot7C, n);
    func_001340C0(slot7C, &D_003BEC20);
    func_00102670(&D_003BEF90, &slot78, func_001029C0);
tail:
    q = lookup.obj;
    m = q->cls->f3A & 5;
    if (m != 0) { goto ret; }
    w = q->cls->f38 & 0x2000;
    if (w == 0) { goto ret; }
    if (*flagp != 0) { goto ret; }
    func_00104440(q);
    cls = o->cls;
    cls->f3A |= 1;
    if ((cls->f3B & 1) != 0) { func_00102670(0, 0, 0); }
    func_00101020(&call60);
    goto loop_head;
ret:
    return o;
}
}
