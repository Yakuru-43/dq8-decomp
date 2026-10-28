// range: 0x1FC510 0x1FC560
#include "common.h"

void func_001FC510(s32 *arg0) {
    s32 var_a2;
    char *temp_a1;

    for (var_a2 = 0; var_a2 < *arg0; var_a2++) {
        if ((var_a2 >= 0) && (var_a2 < *arg0)) {
            temp_a1 = (char *)arg0 + (var_a2 * 4);
            *(s32 *)(temp_a1 + 4) = 0;
            *(s32 *)(temp_a1 + 0x184) = *(s32 *)(temp_a1 + 0xC4);
            *(s32 *)(temp_a1 + 0x304) = 0;
        }
    }
}
