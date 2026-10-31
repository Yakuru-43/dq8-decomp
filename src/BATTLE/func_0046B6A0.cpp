// range: 0x46B6A0 0x46B730
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeB6A0 {
    /* 0x00 */ TagArg a[3];
} NodeB6A0;

typedef union Vec4B6A0 {
    /* 0x00 */ u128 q;
    /* 0x00 */ f32 v[4];
} Vec4B6A0;

struct VecTarget {
    /* 0x00 */ u8 pad0[0xC0];
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
    virtual void f18();
    virtual void f19();
    virtual void f1a();
    virtual void f1b();
    virtual void f1c();
    virtual void f1d();
    virtual void f1e();
    virtual void f1f();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f2a(f32 *); /* slot 0xB0 */
};

typedef struct BattleGlobal {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ VecTarget *field_0C;
} BattleGlobal;

extern "C" {

extern BattleGlobal *D_003E1BB0;

s32 func_0046B6A0(NodeB6A0 *n) {
    Vec4B6A0 vec;
    TagArg *p;
    TagArg *q;
    f32 x0;
    f32 x1;
    f32 x2;

    vec.q = 0;
    p = n->a;
    if (p[0].tag == 0) {
        x0 = (f32)p[0].bits;
    } else {
        x0 = *(f32 *)&p[0].bits;
    }
    vec.v[0] = x0;
    q = p + 1;
    if (q->tag == 0) {
        x1 = (f32)q->bits;
    } else {
        x1 = *(f32 *)&q->bits;
    }
    vec.v[1] = x1;
    if (p[2].tag == 0) {
        x2 = (f32)p[2].bits;
    } else {
        x2 = *(f32 *)&p[2].bits;
    }
    vec.v[2] = x2;
    vec.v[3] = 1.0f;
    D_003E1BB0->field_0C->f2a(vec.v);
    return 1;
}

}
