// range: 0x353E30 0x353EF0
#include "common.h"

void func_00353E30(char *arg0) {
    s32 var_v1;
    s32 var_t5;
    s32 temp_a1;
    s32 cmp_val;
    char *temp_t3;
    char *temp_t1;

    var_v1 = 0;
    do {
        cmp_val = var_v1 + 2;
        temp_t3 = arg0 + (var_v1 * 4);
        var_t5 = 0;
        *(s32 *)(temp_t3 + 0x618) = 0;
        *(s32 *)(temp_t3 + 0x628) = 0;
        *(s32 *)(temp_t3 + 0x608) = -1;
        do {
            temp_t1 = arg0 + (var_t5 * 0x30);
            if (cmp_val == *(s32 *)(temp_t1 + 0x28)) {
                *(s32 *)(temp_t3 + 0x608) = *(s32 *)(temp_t1 + 0x20);
                temp_a1 = *(s32 *)(temp_t1 + 0);
                switch (temp_a1) {
                case 1:
                    *(s32 *)(temp_t3 + 0x628) = *(s32 *)(temp_t3 + 0x628) + 1;
                    break;
                case 2:
                case 3:
                    *(s32 *)(temp_t3 + 0x618) = *(s32 *)(temp_t3 + 0x618) + 1;
                    break;
                }
            }
            var_t5 += 1;
        } while (var_t5 < 0x20);
        var_v1 += 1;
    } while (var_v1 < 4);
}
