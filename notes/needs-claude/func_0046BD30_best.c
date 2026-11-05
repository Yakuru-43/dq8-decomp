// best C for func_0046BD30, see func_0046BD30.md
// range: 0x0046BD30 0x0046BEA0
#include "common.h"

union OutF {
    s128 q;
    f32 f[4];
};

struct Renderer {
    /* 0x00 */ u8 pad0[0xC0];
    /* vtable: slot N sits at 0x8 + 4 * N */
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18(f32);            /* slot 0x68 */
    virtual void f19();
    virtual void f1a();
    virtual void f1b(f32);            /* slot 0x74 */
    virtual void f1c();
    virtual void f1d();
    virtual void f1e(union OutF *);   /* slot 0x80 */
};

typedef struct BattleGlobal {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ char *field_04;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ Renderer *field_0C;
} BattleGlobal;

extern "C" {

extern BattleGlobal *D_003E1BB0;

char *func_16D5B0(char *, s32);                          /* extern */
char *func_151B90(char *, s32);                          /* extern */
void func_149410(char *, union OutF *, union OutF *);    /* extern */
void func_13CD20(f32);                                   /* extern */
void func_13C680(union OutF *, union OutF *, char *);    /* extern */
f32 func_13BCA0(f32);                                    /* extern */
void func_28EEA0(Renderer *, f32, f32, f32);             /* extern */
void func_28EF20(Renderer *, f32);                       /* extern */
void func_28EF30(Renderer *);                            /* extern */
void func_28EF40(Renderer *);                            /* extern */

void func_0046BD30(char *arg0) {
    union OutF vecA0;
    union OutF out90;
    union OutF out80;
    union OutF buf40[4];
    f32 *pa;
    Renderer *renderer;
    char *entry;
    char *g;

    func_16D5B0(D_003E1BB0->field_04, *(s32 *)(arg0 + 0x68));
    renderer = D_003E1BB0->field_0C;
    if (renderer == 0) {
        return;
    }
    if (D_003E1BB0->field_04 == 0) {
        func_28EF30(renderer);
        return;
    }
    entry = func_16D5B0(D_003E1BB0->field_04, *(s32 *)(arg0 + 0x68));
    if (entry == 0) {
        func_28EF30(renderer);
        return;
    }
    g = func_151B90(entry, *(s32 *)(entry + 0x468 + (*(s32 *)(arg0 + 0x6C) << 2)));
    if (g == 0) {
        func_28EF30(renderer);
        return;
    }
    vecA0.q = 0;
    out90.q = 0;
    func_149410(g, &vecA0, &vecA0);
    out90 = *(union OutF *)(entry + 0x190);
    pa = &out90.f[1];
    func_13CD20(*pa);
    func_13C680(&out80, buf40, arg0 + 0x80);
    renderer->f1e(&vecA0);
    func_28EEA0(renderer, out80.f[0], out80.f[1], out80.f[2]);
    func_28EF20(renderer, func_13BCA0(*(f32 *)(arg0 + 0x70) + *pa));
    renderer->f18(*(f32 *)(arg0 + 0x74));
    renderer->f1b(*(f32 *)(arg0 + 0x78));
    func_28EF40(renderer);
}

}
