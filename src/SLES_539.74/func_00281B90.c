// range: 0x281B90 0x281BF0
#include "common.h"

extern s32 func_00286B30(s32, s32);
extern s32 func_00286BE0(s32, s32);

s32 func_00281B90(char *arg0, char *arg1) {
    s32 temp_a0;
    s32 temp_v1;

    temp_a0 = *(s32 *)(arg0 + 4);
    if (temp_a0 == 0) {
        return 0;
    }
    temp_v1 = *(s32 *)(arg1 + 0x28);
    if (temp_v1 == 0) {
        return 0;
    }
    if (*(s32 *)(arg1 + 0x2C) != 0) {
        func_00286BE0(temp_a0, temp_v1);
    } else {
        func_00286B30(temp_a0, temp_v1);
    }
    return 1;
}
