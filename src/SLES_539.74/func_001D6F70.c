// range: 0x1D6F70 0x1D7030
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014DF80(void *);                      /* extern */
M2C_UNK func_0014E240(void *, s32);                 /* extern */
M2C_UNK func_0016BA20(s32, s32);                    /* extern */
void *func_0016BEF0(s32, s32);                      /* extern */
s32 func_001DA3A0(s32, s32, s32 *);                 /* extern */
extern s32 D_003E071C;
extern s32 D_004148AC __attribute__((section(".data")));
extern s32 D_00414920 __attribute__((section(".data")));

s32 func_001D6F70(s32 arg0) {
    s32 sp4C;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v1;
    void *temp_v0;

    sp4C = 0;
    temp_s0 = func_001DA3A0(D_003E071C, (arg0 >> 4) + 1, &sp4C);
    func_0016BA20(D_003E071C, D_004148AC);
    temp_v0 = func_0016BEF0(D_003E071C, D_004148AC);
    if (temp_v0 != NULL) {
        temp_s1 = M2C_FIELD(temp_v0, s32 *, 0x2C);
        func_0014DF80(temp_v0);
        func_0014E240(temp_v0, (temp_s1 - temp_s0) + 1);
    }
    temp_v1 = D_00414920 - sp4C;
    D_00414920 = temp_v1;
    if (temp_v1 <= 0) {
        D_00414920 = 0;
    }
    return temp_s0 * 0x10;
}
