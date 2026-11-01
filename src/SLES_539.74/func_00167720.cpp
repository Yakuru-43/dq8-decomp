// range: 0x00167720 0x001677E0
#include "common.h"

extern "C" {

union Vec4 {
    u128 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
};

struct Mat28 {
    f32 m_00;
    f32 m_04;
    f32 m_08;
    f32 m_0C;
    f32 m_10;
    f32 m_14;
    f32 m_18;
    f32 m_1C;
    f32 m_20;
    f32 m_24;
    s32 m_28;
};

struct Object {
    u8 pad0[0xC0];                  /* 0x00 */
    virtual s32 v0();
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
    virtual s32 v15();
    virtual Mat28 *GetMat();        /* vtable slot 0x48 */
    virtual s32 v16();
    virtual s32 v17();
    virtual s32 v18();
    virtual s32 v19();
    virtual s32 v20();
    virtual s32 v21();
    virtual s32 v22();
    virtual s32 v23();
    virtual s32 v24();
    virtual s32 v25();
    virtual s32 v26();
    virtual s32 v27();
    virtual s32 v28();
    virtual s32 v29();
    virtual s32 v30();
    virtual s32 v31();
    virtual s32 v32();
    virtual s32 v33();
    virtual s32 v34();
    virtual s32 v35();
    virtual void GetBase(Vec4 *out); /* vtable slot 0x9C */
    virtual void GetExt(Vec4 *out);  /* vtable slot 0xA0 */
};

struct Unit : Object {
    u8 padC4[0xE0 - 0xC4];          /* 0xC4 */
    Vec4 base;                      /* 0xE0 */
    Vec4 ext;                       /* 0xF0 */
    u8 pad100[8];                   /* 0x100 */
    s32 state_108;                  /* 0x108 */
};

void func_00167720(Unit *unit) {
    Vec4 base;
    Vec4 ext;
    Mat28 *m;

    if (unit->state_108 == 0) {
        unit->GetBase(&base);
        unit->GetExt(&ext);
        unit->base = base;
        unit->ext = ext;
        m = unit->GetMat();
        m->m_10 = ext.v.y - base.v.y;
        if (m->m_10 < m->m_18) {
            m->m_10 = m->m_18;
        }
        if (!(m->m_10 <= m->m_14)) {
            m->m_10 = m->m_14;
        }
    }
    unit->state_108 = 1;
}

}
