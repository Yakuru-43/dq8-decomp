// range: 0x4679A0 0x467C80
#include "common.h"

extern "C" {

class VFuncs {
public:
    virtual s32 f0(void *); /* slot 0x8 */
};

struct BattleObj {
    u8 pad0[0x5C];
    VFuncs *vf;
    u8 pad60[0x114 - 0x60];
    s32 val_114;
    u8 pad118[0x198 - 0x118];
    s32 val_198;
    u8 pad19C[0x230 - 0x19C];
    s32 val_230;
    s32 val_234;
    s32 val_238;
    s32 val_23C;
    s32 val_240;
    s16 val_244;
    s16 val_246;
    s8 val_248;
    u8 pad249[0x24C - 0x249];
    s32 val_24C;
    u8 pad250[0x260 - 0x250];
    s32 val_260;
};

struct Req4679A0 {
    void *val_00;
    void *val_04;
    s32 val_08;
    void *val_0C;
    s32 val_10;
    M2C_UNK *val_14;
    M2C_UNK *val_18;
    s32 val_1C;
};

extern void *func_14EB30(s32 size, void *arg1);
extern void *func_14EA80(s32 size, void *arg1);
extern void func_14E030(void *);
extern void func_131188(void *, s32, s32); /* memset */
extern void func_1D5CD0(void *);
extern void func_1DB3C0(void *, void *);

extern void *D_003E1B88 __attribute__((section(".sdata")));
extern void *D_003E1B8C __attribute__((section(".sdata")));
extern void *D_003E1B90 __attribute__((section(".sdata")));
extern void *D_003E1B94 __attribute__((section(".sdata")));
extern void *D_003E1B9C __attribute__((section(".sdata")));
extern void *D_003E1BA0 __attribute__((section(".sdata")));
extern void *D_003E1BA4 __attribute__((section(".sdata")));
extern void *D_003E1BA8 __attribute__((section(".sdata")));
extern void *D_003E1BB4 __attribute__((section(".sdata")));
extern void *D_003E1BB8 __attribute__((section(".sdata")));
extern VFuncs D_3DDCC0 __attribute__((section(".data")));
extern VFuncs D_3DF160 __attribute__((section(".data")));
extern M2C_UNK D_00482CE0 __attribute__((section(".data")));
extern M2C_UNK D_00485410 __attribute__((section(".data")));

static inline void init_obj(BattleObj *obj) {
    obj->vf = &D_3DDCC0;
    func_1D5CD0(obj);
    obj->vf->f0(obj);
    obj->vf = &D_3DF160;
    obj->vf->f0(obj);
    obj->val_114 = 0;
    obj->val_198 = 0;
    obj->val_24C = 0;
    obj->val_260 = 0;
    obj->val_230 = 0;
    obj->val_234 = 0;
    obj->val_238 = 1;
    obj->val_23C = 0;
    obj->val_240 = 0;
    obj->val_246 = 0;
    obj->val_248 = 0;
    obj->val_244 = 0;
}

void func_004679A0(void *arg0) {
    BattleObj *obj1;
    BattleObj *obj2;
    Req4679A0 req;
    void *rec;

    D_003E1B9C = 0;
    D_003E1BA0 = 0;
    D_003E1BA4 = 0;
    D_003E1BA8 = 0;
    obj1 = (BattleObj *)func_14EB30(0x270, arg0);
    if (obj1 != 0) {
        init_obj(obj1);
    }
    D_003E1B8C = obj1;
    if (obj1 != 0) {
        obj1->vf->f0(obj1);
        obj2 = (BattleObj *)func_14EB30(0x270, arg0);
        if (obj2 != 0) {
            init_obj(obj2);
        }
        D_003E1B94 = obj2;
        if (obj2 != 0) {
            obj2->vf->f0(obj2);
            func_131188(&req, 0, 0x20);
            func_14E030(arg0);
            D_003E1BB4 = func_14EA80(0x300, arg0);
            func_14E030(arg0);
            rec = func_14EA80(0x120, arg0);
            D_003E1BB8 = rec;
            req.val_0C = rec;
            req.val_10 = 0x18;
            req.val_04 = D_003E1BB4;
            req.val_08 = 0x60;
            req.val_18 = &D_00485410;
            req.val_00 = D_003E1B88;
            req.val_14 = &D_00482CE0;
            req.val_1C = 0x5DC;
            func_1DB3C0(D_003E1B8C, &req);
            func_14E030(arg0);
            D_003E1BB4 = func_14EA80(0x300, arg0);
            func_14E030(arg0);
            rec = func_14EA80(0x120, arg0);
            req.val_0C = rec;
            req.val_08 = 0x60;
            D_003E1BB8 = rec;
            req.val_10 = 0x18;
            req.val_14 = &D_00482CE0;
            req.val_18 = &D_00485410;
            req.val_04 = D_003E1BB4;
            req.val_1C = 0x5DC;
            req.val_00 = D_003E1B90;
            func_1DB3C0(D_003E1B94, &req);
        }
    }
}

}
