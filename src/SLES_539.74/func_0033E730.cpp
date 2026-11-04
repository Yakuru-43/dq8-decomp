// range: 0x33E730 0x33E840
#include "common.h"

extern "C" {

struct Fader {
    u8 pad0[0x1B0];
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
    virtual s32 f3();
    virtual s32 f4();
    virtual s32 f5();
    virtual s32 f6();
    virtual s32 f7();
    virtual s32 f8();
    virtual s32 f9();
    virtual s32 f10();
    virtual s32 f11();
    virtual s32 f12();
    virtual s32 f13();
    virtual s32 f14();
    virtual void update(f32);      /* slot 0x44 */
};

extern f32 D_003E129C;
extern f32 D_003E12A0;
extern Fader *D_004536AC __attribute__((section(".data")));
extern Fader *D_004536A8 __attribute__((section(".data")));
extern void func_00288AA0(void *, f32);

void func_0033E730(void) {
    f32 sum;

    if (D_004536AC == 0) { return; }
    if (D_004536A8 == 0) { return; }
    if (D_003E12A0 == -2.0f) { return; }
    sum = D_003E129C + D_003E12A0;
    D_003E129C = sum;
    if (sum < 0.0f) {
        D_003E129C = 0.0f;
        D_003E12A0 = -2.0f;
    }
    if (D_003E129C > 1.0f) {
        D_003E129C = 1.0f;
        D_003E12A0 = -2.0f;
    }
    func_00288AA0(D_004536A8, 1.0f - D_003E129C);
    func_00288AA0(D_004536AC, D_003E129C);
    D_004536A8->update(1.0f);
    D_004536AC->update(1.0f);
}

}
