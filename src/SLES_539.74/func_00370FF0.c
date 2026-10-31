// range: 0x370FF0 0x371030
#include "common.h"

extern s32 func_0014EA80(s32, char *);

void func_00370FF0(char *arg0, char *arg1, s32 arg2) {
    if (arg1 != NULL) {
        *(s16 *)(arg0 + 8) = arg2;
        *(s32 *)(arg0 + 4) = func_0014EA80((arg2 + 1) * 0x1C, arg1);
    }
}
