// range: 0x00161BA0 0x00161C70
#include "common.h"

extern u32 func_001341D8(char *);
extern char *func_001340C0(char *, char *);

void func_00161BA0(char *path, char *dir, char *name) {
    s32 i;
    char *src;
    s32 n;

    i = func_001341D8(path) - 1;
    while (i >= 0) {
        if (path[i] == '/') {
            break;
        }
        i--;
    }
    if (i == 0) {
        *dir = 0;
        func_001340C0(name, path);
    } else {
        src = path;
        for (n = 0; n <= i; n++) {
            *dir++ = *src++;
        }
        *dir = 0;
        func_001340C0(name, &path[i + 1]);
    }
}
