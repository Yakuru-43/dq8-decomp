// range: 0x37B8D0 0x37B940
#include "common.h"

void func_002F7440(char *);
void func_00372AA0(char *);

void func_0037B8D0(char *arg0) {
    s32 var_s0;
    char *temp_a0;
    char *temp_a0_2;

    var_s0 = 0;
    do {
        temp_a0 = *(char **)(arg0 + (var_s0 * 4));
        if (temp_a0 != NULL) {
            func_00372AA0(temp_a0);
        }
        var_s0 += 1;
    } while (var_s0 < 4);
    temp_a0_2 = *(char **)(arg0 + 0x14);
    if (temp_a0_2 != NULL) {
        func_002F7440(temp_a0_2);
    }
}
