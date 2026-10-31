// range: 0x1D9660 0x1D96D0
#include "common.h"

char *func_0033A1D0(char *, s32);

void func_001D9660(char *arg0) {
    s32 i;
    char *v;

    i = 0;
    while (i < *(s32 *)(arg0 + 0x6B38)) {
        v = func_0033A1D0(arg0 + 0x6B34, i);
        if (v != 0) {
            if (*(s8 *)(v + 0x1DC) == 1) {
                *(s32 *)(v + 0x1E0) = 0;
                *(s8 *)(v + 0x1DC) = 0;
            }
        }
        i++;
    }
}
