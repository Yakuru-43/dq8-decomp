// Best draft for func_00167060 (needs-claude; see func_00167060.md).
// Second function verified byte-identical; the thunk's `jr` tail call is open.
// range: 0x00167060 0x00167130
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
    virtual s32 v36();
    virtual s32 v37();
    virtual s32 v38();
    virtual s32 v39();
    virtual s32 v40();
    virtual s32 v41();
    virtual s32 v42();
    virtual s32 v43();
    virtual s32 v44();              /* vtable slot 0xB8 */
};

struct Unit : Object {
    u8 padC4[0x120 - 0xC4];         /* 0xC4 */
    u128 q_120;                     /* 0x120 */
};

s32 func_00167060(Unit *obj) {
    return obj->v44();              /* want: lw,lw,jr,nop — never emitted */
}

void func_00167070(Unit *src, Unit *dst) {
    Mat28 *m0 = src->GetMat();
    Mat28 *m1 = dst->GetMat();
    *m1 = *m0;
    dst->q_120 = src->q_120;
}

}
