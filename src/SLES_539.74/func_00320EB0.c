// range: 0x320EB0 0x320EF0
#include "common.h"

void func_00320EB0(char *arg0, char *arg1) {
    s32 *counter;
    s32 *check;

    *(char **)(arg0 + 0x1C) = arg1;
    *(s32 *)(arg0 + 0x20) = 0;

    while (arg1 != NULL) {
        check = (s32 *)(arg1 + 4);
        if (*check == 0) {
            break;
        }
        arg1 += 8;
        counter = (s32 *)(arg0 + 0x20);
        *counter = *counter + 1;
    }
}
