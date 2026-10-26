// range: 0x104390 0x104440
// Virtual-base constructor: twin of func_00104060 (idiom "Virtual-base
// constructor"), 8-bit pin, vbase trio D_003DD7C0/D_003DD7CC/D_003DD7A8.
// Byte match needs __ct__/__vt__ aliases (integration) before verify.py.
#include "common.h"

extern "C" void func_00102B30(void *p, s32 value);

struct VB390 {
    virtual void f();
    ~VB390();
    u32 pad04;
    s64 pad08[7];
    s32 f40;
    u8 f44;
    void init(s32 v) { func_00102B30(this, v); f40 = 0; f44 = 0x20; }
};

struct D390 : virtual VB390 {
    virtual void f();
    D390(s32 v);
};

D390::D390(s32 v) {
    init(v);
}
