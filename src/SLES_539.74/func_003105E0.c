// range: 0x3105E0 0x310680
#include "common.h"

struct Slot {
    void *owner;
    char pad4[96];
};

struct Object {
    char pad0[8];
    s32 field8;
    char padC[88];
};

extern struct Slot D_004528A4[] __attribute__((section(".data")));
extern struct Object D_004528A0[] __attribute__((section(".data")));

extern void func_00287110(void *arg0, s32 arg1);
extern void func_0014DF80(void *arg0);

void func_003105E0(s32 index) {
    if (index < 0) {
        return;
    }
    if (index >= 4) {
        return;
    }
    if (D_004528A4[index].owner != NULL) {
        func_00287110(D_004528A4[index].owner, 0);
    }
    D_004528A4[index].owner = NULL;
    func_0014DF80(&D_004528A0[index].field8);
}
