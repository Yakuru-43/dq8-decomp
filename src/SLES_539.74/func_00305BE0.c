// range: 0x305BE0 0x305CB0
#include "common.h"

s32 func_00167A80();                                  /* extern */
s32 func_003763D0(void);                              /* extern */
s32 func_00376390(void);                              /* extern */
void func_003721C0(s32, s32, f32);                     /* extern */
extern f32 D_003D0100[];
extern s8 D_003D0150[];

void func_00305BE0(void) {
    s32 obj;
    s32 i;
    f32 val;

    obj = func_00167A80();
    if (obj == 0) {
        return;
    }
    val = D_003D0100[func_003763D0()];
    func_003721C0(obj, 0, val);
    func_003721C0(obj, 1, val);
    val = D_003D0100[func_00376390()];
    for (i = 0; D_003D0150[i] >= 0; i++) {
        func_003721C0(obj, D_003D0150[i], val);
    }
}
