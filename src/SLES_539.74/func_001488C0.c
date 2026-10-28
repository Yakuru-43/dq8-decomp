// range: 0x1488C0 0x148950
#include "common.h"

char *func_00141CA0(char *, char *);
s32 func_0014E130(s32, s32);
char *func_001428D0();
s32 func_00148D10(char *, char *);

void func_001488C0(char *arg0) {
    char *temp_v0;
    char *temp_s0;
    s32 temp_v0_2;

    temp_v0 = func_001428D0();
    if (temp_v0 != NULL) {
        temp_s0 = (char *)(*(s32 *)(temp_v0 + 0x28) + (*(s32 *)(temp_v0 + 0x2C) << 4));
        if (temp_s0 != NULL) {
            temp_v0_2 = func_00148D10(arg0, temp_s0);
            if (temp_v0_2 > 0) {
                func_0014E130((s32)temp_v0, temp_v0_2);
                func_00141CA0(arg0, temp_s0);
            }
        }
    }
}
