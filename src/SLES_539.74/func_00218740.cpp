// range: 0x218740 0x218780
// MsgObj's constructor: install the vtable (vptr at +0x18, after the data),
// then call its first virtual. The original is `MsgObj::MsgObj() { init(); }`,
// which compiles to these same bytes; until __vt__6MsgObj has an alias to
// D_003DDFF8 the vptr is stored by hand. The virtual call is what gives
// CodeWarrior's `lw t9; lw t9,8(t9); jalr t9` sequence.
#include "common.h"

extern "C" {

extern void *D_003DDFF8[];

struct MsgObj {
    s32 data[6];               /* must precede the first virtual: vptr at +0x18 */
    virtual s32 init();
};

struct MsgObjHeader {
    s32 data[6];
    void **vtbl;
};

MsgObj *func_00218740(MsgObj *obj) {
    ((MsgObjHeader *)obj)->vtbl = D_003DDFF8;
    obj->init();
    return obj;
}

}
