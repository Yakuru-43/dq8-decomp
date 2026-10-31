// range: 0x16A5F0 0x16A740
#include "common.h"

extern void *func_0016A7D0(void *obj);
extern void *func_0016A7B0(void *arg0);
extern void *func_0016A760(void *obj);
extern void *func_0016A740(void *arg0);
extern int func_00131188();
extern void func_00283F10(void *arg0);

extern char D_003DEA10[];
extern char D_003DE8D0[];
extern char D_003DDB40[];
extern char D_003DDB20[];
extern char D_003DDB00[];
extern char D_003DDAE0[];
extern char D_003DDAC0[];

struct Slot {
    s32 a;
    s32 b;
};

struct Named {
    char *name;
    s32 count;
};

struct Init {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
    s32 w4;
    s32 w5;
    f32 scale;
    s32 w7;
    s32 w8;
    s32 w9;
    s32 w10;
    s32 w11;
};

struct Cmd {
    u8 pad0[0x1B0];
    char *table;                      /* 0x1B0 */
    u8 pad1[0x228 - 0x1B4];
    struct Slot slots1[4];            /* 0x228 */
    struct Slot slots2[4];            /* 0x248 */
    u8 pad2[0x4F0 - 0x268];
    struct Init init4F0;              /* 0x4F0 */
    u8 pad3[0x548 - 0x520];
    s32 flags[3];                     /* 0x548 */
    u8 pad4[0x568 - 0x554];
    u8 obj568[8];                     /* 0x568, built by func_00283F10 */
    struct Named named[4];            /* 0x570 */
};

void *func_0016A5F0(struct Cmd *obj) {
    struct Slot *p, *q;
    func_0016A7D0(obj);
    obj->table = D_003DEA10;
    p = &obj->slots1[0];
    do {
        func_0016A7B0(p);
        p++;
    } while (p < &obj->slots1[4]);
    q = &obj->slots2[0];
    do {
        func_0016A7B0(q);
        q++;
    } while (q < &obj->slots2[4]);
    func_0016A760((char *)obj + 0x270);
    func_0016A740((char *)obj + 0x430);
    obj->table = D_003DE8D0;
    func_00131188(&obj->init4F0, 0, 0x2C);
    obj->init4F0.w0 = -1;
    obj->init4F0.w3 = -1;
    obj->init4F0.w4 = -1;
    obj->init4F0.w2 = 1;
    obj->init4F0.w5 = 1;
    obj->init4F0.scale = 1.0f;
    obj->init4F0.w7 = 0;
    obj->init4F0.w8 = -1;
    obj->init4F0.w9 = 0;
    obj->init4F0.w10 = 0;
    obj->flags[0] = 0;
    obj->flags[1] = 0;
    obj->flags[2] = 0;
    func_00283F10(&obj->obj568[0]);
    obj->named[0].name = D_003DDB40;
    obj->named[0].count = 0;
    obj->named[0].name = D_003DDB20;
    obj->named[1].name = D_003DDB40;
    obj->named[1].count = 0;
    obj->named[1].name = D_003DDB00;
    obj->named[2].name = D_003DDB40;
    obj->named[2].count = 0;
    obj->named[2].name = D_003DDAE0;
    obj->named[3].name = D_003DDB40;
    obj->named[3].count = 0;
    obj->named[3].name = D_003DDAC0;
    return obj;
}
