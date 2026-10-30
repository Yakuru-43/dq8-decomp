// range: 0x3630C0 0x363150
#include "common.h"

extern void *func_0016A7D0(void *obj);
extern void *func_0016A7B0(void *arg0);
extern void *func_0016A760(void *obj);
extern void *func_0016A740(void *arg0);

extern char D_003DEA10[];

struct Slot {
    s32 a;
    s32 b;
};

struct Cmd {
    u8 pad0[0x1B0];
    char *table;                      /* 0x1B0 */
    u8 pad1[0x228 - 0x1B4];
    struct Slot slots1[4];            /* 0x228 */
    struct Slot slots2[4];            /* 0x248 */
    u8 pad2[0x270 - 0x268];
    u8 pad3[0x430 - 0x270];
};

void *func_003630C0(struct Cmd *obj) {
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
    return obj;
}
