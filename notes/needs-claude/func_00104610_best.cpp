// range: 0x104610 0x1046C0
// Virtual-base constructor: twin of func_00104110, 16-bit pin, vbase trio
// D_003DD6F0/D_003DD6FC/D_003DD6D8, vbase at +0x8 (no f8 member).
// Byte match needs __ct__/__vt__ aliases (integration) before verify.py.
#include "common.h"

extern "C" void func_00102B30(void *p, s32 value);

struct VB610 {
    virtual void f();
    ~VB610();
    u32 pad04;
    s64 pad08[7];
    s32 f40;
    u16 f44;
    void init(s32 v) { func_00102B30(this, v); f40 = 0; f44 = 0x20; }
};

struct D610 : virtual VB610 {
    virtual void f();
    D610(s32 v);
};

D610::D610(s32 v) {
    init(v);
}
