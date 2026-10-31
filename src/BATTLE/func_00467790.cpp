// range: 0x467790 0x467860
#include "common.h"

extern "C" {

extern void *D_003E1B8C __attribute__((section(".sdata")));
extern void *D_003E1B88 __attribute__((section(".sdata")));
extern s32 D_003E1BB4 __attribute__((section(".sdata")));
extern s32 D_003E1BB8 __attribute__((section(".sdata")));
extern M2C_UNK D_00482CE0 __attribute__((section(".data")));
extern M2C_UNK D_00485410 __attribute__((section(".data")));

extern void func_131188(void *, s32, s32); /* memset */
extern void func_1DB3C0(void *, void *);

struct BattleObj {
    u8 pad0[0x5C];
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 reset(); /* slot 0x10 */
    s32 val_60;
    s32 val_64;
    s32 val_68;
    u8 pad6C[0x21C - 0x6C];
    s32 val_21C;
    s32 val_220;
    s32 val_224;
    s32 val_228;
};

struct Req467790 {
    void *val_00;
    s32 val_04;
    s32 val_08;
    s32 val_0C;
    s32 val_10;
    M2C_UNK *val_14;
    M2C_UNK *val_18;
    s32 val_1C;
};

void func_00467790(void *arg0) {
    Req467790 req;
    BattleObj *obj;

    obj = (BattleObj *)D_003E1B8C;
    obj->reset();
    obj->val_68 = -1;
    obj->val_64 = -1;
    obj->val_21C = 0;
    obj->val_220 = 0;
    obj->val_60 = 0;
    obj->val_224 = 0;
    obj->val_228 = 0;
    func_131188(&req, 0, 0x20);
    if (arg0 != 0) {
        req.val_00 = arg0;
    } else {
        req.val_00 = D_003E1B88;
    }
    req.val_04 = D_003E1BB4;
    req.val_08 = 0x60;
    req.val_0C = D_003E1BB8;
    req.val_10 = 0x18;
    req.val_14 = &D_00482CE0;
    req.val_18 = &D_00485410;
    req.val_1C = 0x5DC;
    func_1DB3C0(D_003E1B8C, &req);
}

}
