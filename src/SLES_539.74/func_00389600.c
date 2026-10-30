// range: 0x389600 0x389660
#include "common.h"

char * func_00201CD0(void);
s32 func_00370FD0(char *);
M2C_UNK func_003705E0(char *);
M2C_UNK func_00388E00();

s32 func_00389600(s32 arg0, s32 arg1) {
    char *temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_00201CD0();
    temp_v0_2 = func_00370FD0(temp_v0);
    if (arg1 == 0) {
        func_003705E0(temp_v0);
        func_00388E00();
    } else {
        *(s16 *)(temp_v0_2 + 0x14) = 0;
        return 0;
    }
    return 0;
}
