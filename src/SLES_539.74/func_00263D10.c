// range: 0x263D10 0x263D60
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0014EB30(M2C_UNK, s32);                  /* extern */
void *func_002226A0(void *);                        /* extern */
extern s8 D_003E0D04;
extern void *D_003E0D08;

void func_00263D10(s32 arg0) {
    void *var_a0;

    var_a0 = func_0014EB30(0x1F48, arg0);
    if (var_a0 != NULL) {
        var_a0 = func_002226A0(var_a0);
    }
    D_003E0D08 = var_a0;
    M2C_FIELD(var_a0, s32 *, 0xF8) = 0x11;
    D_003E0D04 = 0;
}
