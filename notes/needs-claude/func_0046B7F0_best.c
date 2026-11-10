// range: 0x46B7F0 0x46B950
#include "common.h"

typedef struct Mat64 {
    /* 0x00 */ u128 row[4];
} Mat64;

typedef union Vec4 {
    /* 0x00 */ u128 q;
    /* 0x00 */ f32 v[4];
} Vec4;

typedef struct StateB7F0 {
    /* 0x00 */ u8 pad0[0x64];
    /* 0x64 */ s32 n_64;
    /* 0x68 */ s32 n_68;
} StateB7F0;

struct BattleObject {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ Mat64 mat;
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
    virtual void get_0a4(f32 *v); /* slot 0xA4 */
    virtual void get_0a8(f32 *v); /* slot 0xA8 */
    virtual void f42();           /* slot 0xAC */
    virtual void put_0b0(f32 *v); /* slot 0xB0 */
    virtual void put_0b4(f32 *v); /* slot 0xB4 */
};

extern "C" {

extern StateB7F0 *D_003E1B8C;

void func_0013C680(void *dst, void *mat, void *vec);
void func_0013D2B0(void *mat);
void *func_00168160(void);
void *func_0016AF30(void *, s32);

void func_0046B7F0(void) {
    Vec4 vecD0;
    Vec4 vecC0;
    Mat64 mat;
    u128 *o1;
    u128 *o2;
    u128 *o3;
    u128 *m1;
    u128 *m2;
    u128 *m3;
    void *sys;
    BattleObject *obj;

    sys = func_00168160();
    if (sys == 0) {
        return;
    }
    obj = (BattleObject *)func_0016AF30(sys, *(s32 *)((char *)sys + 0x44B4));
    if (obj == 0) {
        return;
    }
    D_003E1B8C->n_64 = -1;
    D_003E1B8C->n_68 = -1;
    obj->get_0a4(vecD0.v);
    obj->get_0a8(vecC0.v);
    m1 = &mat.row[1];
    m2 = &mat.row[2];
    m3 = &mat.row[3];
    o1 = &obj->mat.row[1];
    o2 = &obj->mat.row[2];
    o3 = &obj->mat.row[3];
    mat.row[0] = obj->mat.row[0];
    *m1 = *o1;
    *m2 = *o2;
    *m3 = *o3;
    func_0013C680(vecD0.v, mat.row, vecD0.v);
    func_0013C680(vecC0.v, mat.row, vecC0.v);
    func_0013D2B0(mat.row);
    obj->put_0b0(vecD0.v);
    obj->put_0b4(vecC0.v);
    obj->mat.row[0] = mat.row[0];
    *o1 = *m1;
    *o2 = *m2;
    *o3 = *m3;
}

}
