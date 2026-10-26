// range: 0x1041C0 0x104390
// Draft: streambuf-style member with a local object (func_00106380 ctor at
// fp+0x88), one virtual call through buf->f20's vtable slot 0x18, three
// streambuf helpers, then a tail check that can recurse. Twin of
// func_00104440 (calls func_00106660 instead of func_00106380).
#include "common.h"

extern s32 func_00106380(void *local, void *obj);
extern s32 func_001341D8(char *name);
extern void func_00100860(s32 a0);
extern void func_00102C10(void *a, s32 b);
extern void func_001340C0(void *a, char *b);
extern void func_00102670(void *a, void *b, void *c);
extern void func_00101020(void *a);
extern void func_001029C0(void);
extern s32 buf_call(void *p); /* the jalr t9 through f20's vtable slot 0x18 */

extern char D_003BEC20[];
extern char D_003BEF90[];
extern M2C_UNK D_003DD6B0 __attribute__((section(".data")));

struct Buf {
    /* 0x00 */ void *vptr;      /* read for the virtual call */
    /* 0x20 */ void *f20;       /* object whose vtable slot 0x18 is called */
    /* 0x38 */ u16 f38;
    /* 0x3A */ u8 f3A;
    /* 0x3B */ u8 f3B;
};

struct Obj {
    /* 0x00 */ struct Buf *buf;
};

void *func_001041C0(struct Obj *obj) {
    struct Buf *buf;
    u8 local[2];
    u8 local2[0x40];
    s32 ok;
    s32 r;

    func_00106380(local, obj);
    local[1] = 1;
    ok = 0;
    if (obj->buf->f20 != 0) {
        r = buf_call(obj->buf->f20);
        if (r == -1) {
            ok = 1;
        }
    }
    if (ok == 0) {
        goto tail;
    }
    buf = obj->buf;
    buf->f3A |= 1;
    if (buf->f20 == 0) {
        buf->f3A |= 1;
    }
    if (((u8)(buf->f3A & buf->f3B) & 0xFF) == 0) {
        goto tail;
    }
    {
        void *vt = &D_003DD6B0;
        s32 n;
        *(void **)local2 = vt;
        r = func_001341D8(D_003BEC20);
        func_00100860(r + 1);
        func_00102C10(&local2[4], r);
        func_001340C0(*(void **)&local2[4], D_003BEC20);
        func_00102670(D_003BEF90, local2, func_001029C0);
    }
tail:
    {
        struct Obj *t = *(struct Obj **)&local2[4];
        if ((((struct Buf *)t->buf)->f3A & 5) == 0) {
            if ((((struct Buf *)t->buf)->f38 & 0x2000) != 0 && local[1] == 0) {
                func_001041C0(t);
            }
        }
    }
    return obj;
}
