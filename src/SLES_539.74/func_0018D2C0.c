// range: 0x18D2C0 0x18D350
#include "common.h"

void func_0018D2C0(char *arg0, char *arg1) {
    s8 temp_v1;
    s32 a2;

    if (arg1 != NULL) {
        temp_v1 = *(s8 *)(arg0 + 0x5340);
        a2 = 1;
        switch (temp_v1) {
        case 1:
            *(s32 *)(arg1 + 0x520) = 0x43480000;
            *(s32 *)(arg1 + 0x524) = 0x43820000;
            *(s32 *)(arg1 + 0x528) = 0;
            *(s32 *)(arg1 + 0x52C) = 0x40000000;
            *(s32 *)(arg1 + 0x504) = 0;
            break;
        case 0:
            *(s32 *)(arg1 + 0x520) = 0x43480000;
            *(s32 *)(arg1 + 0x524) = 0x43820000;
            *(s32 *)(arg1 + 0x528) = 0;
            *(s32 *)(arg1 + 0x52C) = 0x40000000;
            *(s32 *)(arg1 + 0x504) = 1;
            break;
        default:
            *(s32 *)(arg1 + 0x520) = 0x41A00000;
            *(s32 *)(arg1 + 0x524) = 0x43700000;
            *(s32 *)(arg1 + 0x528) = 0;
            *(s32 *)(arg1 + 0x52C) = 0x40000000;
            *(s32 *)(arg1 + 0x504) = a2;
            break;
        }
    }
}
