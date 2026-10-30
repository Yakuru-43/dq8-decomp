// range: 0x2C6860 0x2C68B0
#include "common.h"

extern char *D_003E0434;
extern s32 D_003E0818;
extern char D_00415880[];

void func_002C6860(void) {
    s32 temp_v1;
    s32 var_a2;
    char *temp_a0;

    D_003E0818 = 0;
    if (D_003E0434 != NULL) {
        *(s32 *)(D_003E0434 + 0x1754) = 0;
    }
    var_a2 = 0;
    do {
        temp_v1 = var_a2 * 0x30;
        var_a2 += 1;
        temp_a0 = &D_00415880[temp_v1];
        *(s32 *)(temp_a0 + 0x20) = 0;
        *(s32 *)(temp_a0 + 0x24) = 0;
    } while (var_a2 < 2);
}
