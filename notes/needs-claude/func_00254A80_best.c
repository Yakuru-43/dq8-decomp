// range: 0x00254A80 0x00254B30
#include "common.h"

extern char D_0041C8D0[];
extern char *D_0041C8E4 __attribute__((section(".data")));

extern s32 func_00133F78(char *, char *);

char *func_00254A80(char *name) {
    char *entry;
    s32 i;

    if (name == NULL) {
        return D_0041C8E4;
    }
    if (name[0] == 0) {
        return D_0041C8E4;
    }
    entry = D_0041C8D0;
    i = 0;
    while (i < 4) {
        if (*(char **)(entry + 0x14) != NULL) {
            if (func_00133F78(entry, name) == 0) {
                break;
            }
        }
        i++;
        entry += 0x18;
    }
    return *(char **)(entry + 0x14);
}
