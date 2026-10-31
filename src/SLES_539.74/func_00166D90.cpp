// range: 0x00166D90 0x00166E20
#include "common.h"

extern "C" {

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
};

struct Unit : Object {
    u8 padC4[0x130 - 0xC4];         /* 0xC4 */
    f32 f_130;
    f32 f_134;
    f32 f_138;
    f32 f_13C;
    f32 f_140;
    f32 f_144;
    f32 f_148;
    f32 f_14C;
    f32 f_150;
    f32 f_154;
    s32 n_158;
};

void func_00166D90(Unit *unit) {
    Mat28 *m = unit->GetMat();
    unit->f_130 = m->m_00;
    unit->f_134 = m->m_04;
    unit->f_138 = m->m_08;
    unit->f_13C = m->m_0C;
    unit->f_140 = m->m_10;
    unit->f_144 = m->m_14;
    unit->f_148 = m->m_18;
    unit->f_14C = m->m_1C;
    unit->f_150 = m->m_20;
    unit->f_154 = m->m_24;
    unit->n_158 = m->m_28;
}

}
