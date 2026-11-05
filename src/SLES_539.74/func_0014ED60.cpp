// range: 0x0014ED60 0x0014EDF0
#include "common.h"

extern "C" {

struct Base14ED60 {
    s32 data[0x50 / 4]; /* must precede the first virtual: vptr at +0x50 */
    virtual s32 m0();
    virtual s32 m2(s32);
};

struct Obj14ED60 : Base14ED60 {
    char gap54[0x64 - 0x54];
    u32 f64;
    char gap68[0x128 - 0x68];
    s32 f128;
    u32 f12C;
};

s32 func_0014ED60(Obj14ED60 *o) {
    s32 ret;
    u8 c;

    ret = 0;
    if (o->m2(2) != 0) {
        c = (0 < o->f128);
        if (c != 0) {
            c = (0 < o->f12C);
        }
        if (c != 0) {
            ret = ret | 1;
        }
        if (((o->f64 ^ 0x20) != 0) != false) {
            ret = ret | 2;
        }
    }
    return ret;
}

}
