// range: 0x255EA0 0x255F30
#include "common.h"

extern "C" {

struct MgObj {
    u8 pad0[0x1B0];                  /* 0x00 */
    virtual void v_08(void);
    virtual void v_0C(void);
    virtual void v_10(void);
    virtual void v_14(void);
    virtual void v_18(f32 scale);
    virtual void v_1C(void);
    virtual void v_20(void);
    virtual void v_24(void);
    virtual void v_28(void);
    virtual void v_2C(void);
    virtual void v_30(void);
    virtual void v_34(void);
    virtual void v_38(void);
    virtual void v_3C(void);
    virtual void v_40(void);
    virtual void v_44(f32 scale);
};

struct MgUnit : MgObj {
    u8 pad1B4[0x4DC - 0x1B4];        /* 0x1B4 */
    s32 key_4DC;                     /* 0x4DC */
};

extern MgUnit *D_003E0BFC;

void *func_0015F490(void);
s32 func_001419A0(void *obj, s32 key, f32 amount);

void func_00255EA0(void) {
    void *mdl;

    if (D_003E0BFC == 0) {
        return;
    }
    D_003E0BFC->v_44(1.0f);
    mdl = func_0015F490();
    func_001419A0(mdl, D_003E0BFC->key_4DC, 1.0f);
    D_003E0BFC->v_18(1.0f);
    D_003E0BFC->v_24();
}

}
