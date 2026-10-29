// range: 0x302FB0 0x303140
#include "common.h"

typedef union {
    u128 q;
    f32 f[4];
} Vec4;

void *func_0014E560(void *, s32);
void func_0014E500(void *, void *);
void func_0013E090(Vec4 *);
void func_0013B790(Vec4 *, Vec4 *, f32);
void func_0013B7B0(Vec4 *, Vec4 *, Vec4 *);
void func_0013B7D0(Vec4 *, Vec4 *, Vec4 *);
s32 func_0016DD20(void *, void *, Vec4 *, s32);
s32 func_001E6710(void *, s32, Vec4 *, Vec4 *, f32, s32);

f32 func_00302FB0(void *obj, Vec4 *pos, f32 limit) {
    s32 idx;
    Vec4 vecSub;
    Vec4 vecAdd;
    Vec4 out;
    Vec4 cur;
    Vec4 scale;
    f32 acc;
    f32 result;
    s32 flag;
    void *handle;
    void *mgr;

    if (obj == NULL) {
        return 0.0f;
    }
    mgr = M2C_FIELD(obj, void **, 0x54C);
    if (mgr == NULL) {
        return 0.0f;
    }
    flag = 0xC4;
    handle = func_0014E560(mgr, 0x498);
    if (handle == NULL) {
        flag = 0;
    }
    func_0013E090(&scale);
    func_0013B790(&scale, &scale, 120.0f);
    func_0013B7D0(&vecSub, pos, &scale);
    func_0013B7B0(&vecAdd, pos, &scale);
    vecSub.f[3] = 1.0f;
    acc = 0.0f;
    vecAdd.f[3] = 1.0f;
    result = pos->f[1];
    cur.q = pos->q;
    while (acc < limit) {
        idx = func_0016DD20(obj, handle, &vecAdd, flag);
        cur.f[1] -= 60.0f;
        if (0 <= func_001E6710(handle, idx, &cur, &out, 120.0f, 0x11)) {
            result = out.f[1];
            break;
        }
        acc += 60.0f;
        vecAdd.f[1] -= 60.0f;
        vecSub.f[1] -= 60.0f;
    }
    func_0014E500(mgr, handle);
    return result;
}
