// range: 0x16E410 0x16E530
#include "common.h"

extern "C" {

typedef union Vec {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
} Vec;

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
    virtual s32 FillScalars(f32 *out);  /* slot 0x94 */
    virtual s32 FillVec(Vec *out);      /* slot 0x98 */
    virtual s32 v37();
    virtual s32 v38();
    virtual s32 v39();
    virtual s32 v40();
    virtual s32 v41();
    virtual s32 v42();
    virtual s32 v43();
    virtual f32 GetWeight(void);        /* slot 0xB8 */
};

struct Unit : Object {
    u8 padC4[0xF0 - 0xC4];          /* 0xC4 */
    Vec vec_F0;                     /* 0xF0 */
};

extern void *func_0013A900(f32 value);
extern void *func_00129710(void *a0);
extern void *func_00129108(void *a0);
extern void *func_0013ADF8(void *a0, void *a1);
extern void *func_0013AD38(void *a0, void *a1);
extern f32 func_0013B4B8(void *a0);

void func_0016E410(Unit *unit, f32 value) {
    Vec vec;
    f32 scalars[4];
    void *r1;
    void *r2;
    void *r3;
    void *r4;
    void *r5;

    unit->FillScalars(scalars);
    unit->FillVec(&vec);

    r1 = func_0013A900(unit->GetWeight());
    r2 = func_00129710(r1);
    r3 = func_0013A900(value);
    r4 = func_0013ADF8(r3, r2);
    r5 = func_0013A900(scalars[0]);
    vec.v.x = func_0013B4B8(func_0013AD38(r5, r4));

    r1 = func_0013A900(unit->GetWeight());
    r2 = func_00129108(r1);
    r3 = func_0013A900(value);
    r4 = func_0013ADF8(r3, r2);
    r5 = func_0013A900(scalars[2]);
    vec.v.z = func_0013B4B8(func_0013AD38(r5, r4));

    unit->vec_F0 = vec;
}

}
