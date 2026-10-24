// range: 0x102FB0 0x1030B0
// Destructor of a reference-counted object: drops the global count in
// D_003E1D08, and at zero destroys the three sub-objects and dispatches
// their virtual v_0x08 with -1 (CodeWarrior vcall idiom lw t9 / lw t9 /
// jalr t9).  `n > 0` frees the object itself, like func_00102B90.
#include "common.h"

extern "C" {

struct Counted {                    /* &D_003E1D20: vptr at +0x10 */
    s32 data[4];                    /* must precede the first virtual */
    virtual void v_0x08(s32 arg);
};

struct SubObject {                  /* &D_003E1D90 etc.: vptr at +0x4 */
    s32 field_00;
    virtual void v_0x08(s32 arg);
};

extern s32 D_003E1D08 __attribute__((section(".data")));
extern Counted D_003E1D20 __attribute__((section(".data")));
extern SubObject D_003E1D90 __attribute__((section(".data")));
extern SubObject D_003E1E50 __attribute__((section(".data")));
extern SubObject D_003E1DF0 __attribute__((section(".data")));

extern void func_001041C0(void *obj);
extern void func_001007A0(void *node);

void *func_00102FB0(void *obj, s16 n) {
    s32 count;
    Counted *counted;
    SubObject *sub90;
    SubObject *subE50;
    SubObject *subF0;

    if (obj != 0) {
        count = D_003E1D08 - 1;
        D_003E1D08 = count;
        if (count == 0) {
            counted = &D_003E1D20;
            sub90 = &D_003E1D90;
            subE50 = &D_003E1E50;
            subF0 = &D_003E1DF0;
            func_001041C0(sub90);
            func_001041C0(subE50);
            func_001041C0(subF0);
            counted->v_0x08(-1);
            sub90->v_0x08(-1);
            subE50->v_0x08(-1);
            subF0->v_0x08(-1);
        }
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}

}
