// range: 0x16A760 0x16A7B0
// Installs the two static tables on the command object (the vptr at +0xF0 is
// stored by hand through the twin struct; __vt__ has no alias yet), then makes
// the virtual call on the sub-object at +0x10 -- the virtual is what gives the
// `lw $t9; lw $t9,0x10($t9); jalr $t9` sequence.
#include "common.h"

extern "C" {

extern void *D_003DD8A0[];
extern void *D_003DD8C0[];

struct CmdBase {
    s32 data[56];              /* 0x00..0xDF: the vptr lands at +0xE0 */
    virtual s32 f0();          /* slot 0x8 */
    virtual s32 f1();          /* slot 0xC */
    virtual s32 f2();          /* slot 0x10, the one called here */
};

struct CmdObj {
    u8 head[0x10];             /* 0x00 */
    CmdBase cmd;               /* 0x10; its vptr is at 0xF0 */
    u8 tail[0x1B0 - 0xF4];
    void **table;              /* 0x1B0 */
};

struct CmdObjRaw {
    u8 head[0x10];
    u8 padE0[0xE0];
    void **vtbl;               /* 0xF0 */
    u8 padBC[0x1B0 - 0xF4];
    void **table;              /* 0x1B0 */
};

CmdObj *func_0016A760(CmdObj *obj) {
    ((CmdObjRaw *)obj)->table = D_003DD8C0;
    ((CmdObjRaw *)obj)->vtbl = D_003DD8A0;
    obj->cmd.f2();
    return obj;
}

}
