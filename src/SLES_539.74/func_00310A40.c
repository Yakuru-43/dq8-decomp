// range: 0x310A40 0x310AF0
#include "common.h"

struct Object {
    s32 field0;
    s32 field4;
    s32 field8;
    char padC[88];
};

extern struct Object D_004528A0[] __attribute__((section(".data")));
extern s32 D_004528A4 __attribute__((section(".data")));
extern s32 D_004528A8 __attribute__((section(".data")));

extern void func_0014DF10(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0014E130(s32 arg0, s32 arg1);

void func_00310A40(s32 arg0) {
    s32 i;
    s32 result;

    for (i = 0; i < 4; i++) {
        D_004528A0[i].field0 = i;
        D_004528A0[i].field4 = 0;
        func_0014DF10(&D_004528A0[i].field8, 0, 0);
    }
    result = func_0014E130(arg0, 0xC80);
    D_004528A0[0].field0 = 0;
    D_004528A4 = 0;
    func_0014DF10(&D_004528A8, result, 0xC80);
}
