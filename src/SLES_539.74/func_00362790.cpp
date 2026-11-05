// range: 0x362790 0x362830
#include "common.h"

extern "C" {

struct PartyUnit {
    u8 pad0[0x1B0];                         /* 0x000 */
    virtual void f0(void);
    virtual void f1(void);
    virtual void f2(void);
    virtual void f3(void);
    virtual void set_scale(f32);            /* slot 0x18 */
    virtual void f5(void);
    virtual void f6(void);
    virtual void update(void);              /* slot 0x24 */
    u8 pad1B4[0x328];                       /* 0x1B4 */
    s32 count;                              /* 0x4DC */
    u8 pad4E0[0x20];                        /* 0x4E0 */
};

extern PartyUnit *D_003E1434;
extern s16 D_003E142C;

void *func_0015F490();                      /* extern */
void func_001419A0(void *, s32, f32);       /* extern */

void func_00362790(void) {
    PartyUnit *arr;
    void *handle;
    s32 i;

    if (D_003E1434 == 0) {
        return;
    }
    handle = func_0015F490();
    arr = D_003E1434;
    func_001419A0(handle, arr->count, 1.0f);
    for (i = 0; i < D_003E142C;) {
        arr->set_scale(1.0f);
        arr->update();
        i++;
        arr++;
    }
}

}
