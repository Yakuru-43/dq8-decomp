// range: 0x181030 0x181130
#include "common.h"

extern "C" {

extern void *D_003DD8A0[];
extern void *D_003DD8C0[];
extern void *D_003DDA80[];
extern void *D_003DEA10[];

void func_001E7EB0(void *p);

struct Pair {
    s32 lo;
    s32 hi;
};

struct Sub {
    s32 data[0x38];            /* vptr at +0xE0 */
    virtual void v0();
    virtual void v1();
    virtual void v2();
    s32 pad0[0x2F];
    void **vtblB;              /* +0x1A0 */
    s32 pad1[3];
    s32 z0;                    /* +0x1B0 */
    s32 z1;
    s32 z2;
    s32 z3;
    s32 z4;
    s32 pad2[7];
    s32 w0[14];                /* +0x1E0 */
    Pair pairs[8];             /* +0x218 */
    s32 pad3[6];
};

struct SubTwin {
    s32 data[0x38];
    void **vtbl;
};

struct Obj {
    s32 head[4];
    Sub sub1;                  /* +0x10 */
    Sub sub2;                  /* +0x280 */
};

Obj *func_00181030(Obj *o) {
    Pair *p;
    Pair *q;

    o->sub1.vtblB = D_003DD8C0;
    ((SubTwin *)&o->sub1)->vtbl = D_003DD8A0;
    o->sub1.v2();
    o->sub1.vtblB = D_003DDA80;
    func_001E7EB0(&o->sub1.w0[0]);
    o->sub1.vtblB = D_003DEA10;
    p = &o->sub1.pairs[0];
    do {
        p->hi = -1;
        p->lo = -1;
        p++;
    } while (p < &o->sub1.pairs[4]);
    q = &o->sub1.pairs[4];
    do {
        q->hi = -1;
        q->lo = -1;
        q++;
    } while (q < &o->sub1.pairs[8]);
    o->sub2.vtblB = D_003DD8C0;
    ((SubTwin *)&o->sub2)->vtbl = D_003DD8A0;
    o->sub2.v2();
    o->sub2.z0 = 0;
    o->sub2.z2 = 0;
    o->sub2.z1 = 0;
    o->sub2.z4 = 0;
    o->sub2.z3 = 0;
    return o;
}

}
