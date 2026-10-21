// range: 0x2FE1E0 0x2FE2B0
#include "common.h"

extern char D_003CFF68[];   /* "<ss>" */
extern char D_003CFF70[];   /* "<SCHARFEN_S>" */
extern s32 func_002E3380(char *, char *);

s32 func_002FE1E0(char *arg0) {
    s32 c;

    if (arg0 == 0) {
        return 0;
    }
    c = *arg0;
    if (c == 's' || c == 'z' || c == 'x' || c == 'S' || c == 'Z' || c == 'X') {
        return 1;
    }
    if (c != '>') {
        return 0;
    }
    if (func_002E3380(arg0 - 3, D_003CFF68) == 0) {
        return 1;
    }
    return func_002E3380(arg0 - 0xB, D_003CFF70) == 0;
}
