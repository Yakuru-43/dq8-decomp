// range: 0x2FE120 0x2FE1E0
#include "common.h"

s32 func_002FE120(char *arg0, char *arg1) {
    char *start;
    s32 isComment;
    s32 c;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    start = arg1;
    while (1) {
        c = *arg0;
        if (c == 0 || c == '@') {
            *arg1 = c;
            return (s32)(arg1 + 1 - start);
        }
        if (c == '/' && arg0[1] == '/') {
            isComment = 1;
        } else {
            isComment = 0;
        }
        if (isComment == 0) {
            *arg1 = c;
            arg0++;
            arg1++;
            continue;
        }
        for (arg0 += 2; (c = *arg0) != 0; arg0++) {
            if ((s8)c == 0x0A) {
                arg0++;
                break;
            }
        }
    }
}
