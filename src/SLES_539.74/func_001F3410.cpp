// range: 0x1F3410 0x1F3450
// MsgObj's constructor: install the vtable (vptr at +0x14, after the data),
// then call its first virtual. The original is `MsgObj::MsgObj() { init(); }`,
// which compiles to these same bytes; until __vt__6MsgObj has an alias to
// D_003DDE68 the vptr is stored by hand. The virtual call is what gives
// CodeWarrior's `lw t9; lw t9,8(t9); jalr t9` sequence.
#include "common.h"

extern "C" {

extern void *D_003DDE68[];

struct MsgObj {
    s32 data[5];               /* must precede the first virtual: vptr at +0x14 */
    virtual s32 init();
};

struct MsgObjHeader {
    s32 data[5];
    void **vtbl;
};

MsgObj *func_001F3410(MsgObj *obj) {
    ((MsgObjHeader *)obj)->vtbl = D_003DDE68;
    obj->init();
    return obj;
}

}
