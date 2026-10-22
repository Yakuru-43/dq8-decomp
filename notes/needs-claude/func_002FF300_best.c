// range: 0x2FF300 0x2FF6E0
#include "common.h"

struct Float4 { f32 a, b, c, d; };
struct Src {                /* arg0: int fields +0..0xC, arr at +0x10, mode at +0x20 */
    s32 x0, x1, x2, x3;
    s32 arr[4];
    s32 mode;
};
struct Prim {               /* 8-aligned: hole at sp+0xC0 */
    u8 r, g, b, a;
    s64 unk;
};

void func_002E2970(s32, u8 *);
void func_002FFAD0(void *, s32 *, s32, s32);
void func_002FFE10(void *, s32 *, s32, u8 *);
void func_002FF890(void *, s32, s32, s32, s32);
s32 func_002E3410(void);
void func_0013E2D0(void *, s32);
void func_0013E320(void *, s32);
void func_0013EB30(void *, s32);
void func_0013ECD0(void *, s32, s32, s32, s32);
void func_0013EF90(void *, s32, s32, s32);
void func_0013F450(void *);
void func_0013F6C0(void *, s32);

static inline s32 GetArr(struct Src *a, s32 idx) {
    if (idx >= 0 && idx < 4) {
        return a->arr[idx];
    }
    return -1;
}

void func_002FF300(struct Src *a, void *obj, struct Float4 *def, s32 color,
                   s32 arg4, s32 arg5) {
    struct Float4 d;
    s32 c[4];
    struct Prim p;
    s32 div;
    s32 v;
    s32 q;
    s32 x;
    s32 y;
    s32 z;
    s32 w;
    s32 i;

    d = *def;
    if (obj == 0) {
        return;
    }
    v = a->x0;
    if (v < 0) {
        v = *(s32 *)&d.a;
    }
    c[0] = v;
    v = a->x1;
    if (v < 0) {
        v = *(s32 *)&d.b;
    }
    c[1] = v;
    v = a->x2;
    if (v < 0) {
        v = *(s32 *)&d.c;
    }
    c[2] = v;
    v = a->x3;
    if (v < 0) {
        v = *(s32 *)&d.d;
    }
    c[3] = v;
    c[0] += 2;
    c[1] += 2;
    c[2] -= 4;
    c[3] -= 4;
    func_002FFAD0(obj, c, arg4, c[1]);
    p.r = 0x80;
    p.g = 0x80;
    p.b = 0x80;
    p.a = (u8)color;
    c[0] -= 2;
    c[1] -= 2;
    c[2] += 4;
    c[3] += 4;
    func_002E2970(a->mode, (u8 *)&p);
    div = 18;
    q = arg5 / div;
    if (arg5 % div != 0) {
        q++;
    }
    func_002FFE10(obj, c, q, (u8 *)&p);
    w = c[3] - 14;
    x = c[0] + 6;
    y = c[1] + 8;
    z = c[2] - 10;
    func_0013E320(obj, 0);
    func_0013E2D0(obj, 1);
    func_0013F6C0(obj, 3);
    func_0013ECD0(obj, 0, 0, 0, 0);
    func_0013EF90(obj, x + z, y, 0);
    y += w;
    func_0013EF90(obj, x, y, 0);
    func_0013ECD0(obj, 0, 0, 0, 0x40);
    func_0013EF90(obj, x + z, y, 0);
    func_0013F450(obj);
    func_0013E320(obj, 1);
    func_0013E2D0(obj, 0);
    x = c[3];
    y = c[0];
    if (obj == 0) {
        return;
    }
    z = c[2];
    func_0013F6C0(obj, 6);
    func_0013EB30(obj, func_002E3410());
    func_0013ECD0(obj, 0x80, 0x80, 0x80, (color << 7) / 0x80);
    for (i = 0; i < 4; i++) {
        if (0 <= GetArr(a, i)) {
            func_002FF890(obj, y, GetArr(a, i) + z - 3, x, color);
        }
    }
    func_0013F450(obj);
}
