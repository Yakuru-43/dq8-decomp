// range: 0x16A7D0 0x16A830
// Twin of func_0016A760: install the tables, make the virtual call on the
// sub-object at +0x10, then point the table at the second static and init the
// payload at +0x1F0. The hand vptr store goes through the twin struct
// (__vt__ has no alias yet).
#include "common.h"

extern "C" {

extern void *D_003DD8A0[];
extern void *D_003DD8C0[];
extern void *D_003DDA80[];

extern void func_001E7EB0(void *arg0);

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
    u8 more[0x1F0 - 0x1B4];
    u8 payload;                /* 0x1F0 */
};

struct CmdObjRaw {
    u8 head[0x10];
    u8 padE0[0xE0];
    void **vtbl;               /* 0xF0 */
    u8 pad1[0x1B0 - 0xF4];
    void **table;              /* 0x1B0 */
    u8 pad2[0x1F0 - 0x1B4];
    u8 payload;                /* 0x1F0 */
};

CmdObj *func_0016A7D0(CmdObj *obj) {
    obj->table = D_003DD8C0;
    ((CmdObjRaw *)obj)->vtbl = D_003DD8A0;
    obj->cmd.f2();
    obj->table = D_003DDA80;
    func_001E7EB0(&obj->payload);
    return obj;
}

}
