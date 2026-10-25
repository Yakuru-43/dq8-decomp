// range: 0x1FA430 0x1FA4C0
// auto: m2c draft, verified byte-exact
// rodata: 0x3C72A0 0x3C72BC
#include "common.h"

u32 func_001667C0();                                /* extern */
extern s32 D_003E07B0;
extern char *D_003E07C8;

s32 func_001FA430(void) {
    u32 var_v0;

    if (D_003E07C8 == NULL) {
        return 0;
    }
    var_v0 = func_001667C0();
    switch (var_v0) {
    case 0:
        var_v0 = 0;
        break;
    case 1:
        var_v0 = 1;
        break;
    case 2:
        var_v0 = 3;
        break;
    case 3:
    case 4:
        D_003E07B0 = 0;
        var_v0 = 4;
        break;
    case 5:
        var_v0 = 9;
        break;
    case 6:
        var_v0 = 0x10;
        break;
    }
    M2C_FIELD(D_003E07C8, u32 *, 4) = var_v0;
    return 1;
}
