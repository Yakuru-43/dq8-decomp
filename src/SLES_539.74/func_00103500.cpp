// range: 0x103500 0x103600
// Sibling of func_00102FB0: drops the global count in D_003E1D10, and at
// zero tears down the three sub-objects in D_003E1F20/F80/FE0 and dispatches
// their virtual v_0x08 with -1.  `n > 0` frees the object itself.
#include "common.h"

extern "C" {

struct Counted {                    /* &D_003E1EB0: vptr at +0x10 */
    s32 data[4];                    /* must precede the first virtual */
    virtual void v_0x08(s32 arg);
};

struct SubObject {                  /* &D_003E1F20 etc.: vptr at +0x4 */
    s32 field_00;
    virtual void v_0x08(s32 arg);
};

extern s32 D_003E1D10 __attribute__((section(".data")));
extern Counted D_003E1EB0 __attribute__((section(".data")));
extern SubObject D_003E1F20 __attribute__((section(".data")));
extern SubObject D_003E1FE0 __attribute__((section(".data")));
extern SubObject D_003E1F80 __attribute__((section(".data")));

extern void func_00104440(void *obj);
extern void func_001007A0(void *node);

void *func_00103500(void *obj, s16 n) {
    s32 count;
    Counted *counted;
    SubObject *sub20;
    SubObject *subE0;
    SubObject *sub80;

    if (obj != 0) {
        count = D_003E1D10 - 1;
        D_003E1D10 = count;
        if (count == 0) {
            counted = &D_003E1EB0;
            sub20 = &D_003E1F20;
            subE0 = &D_003E1FE0;
            sub80 = &D_003E1F80;
            func_00104440(sub20);
            func_00104440(subE0);
            func_00104440(sub80);
            counted->v_0x08(-1);
            sub20->v_0x08(-1);
            subE0->v_0x08(-1);
            sub80->v_0x08(-1);
        }
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}

}
