// range: 0x2C0200 0x2C0250
#include "common.h"

extern char D_0044ECD0[];

char *func_002C0200(s32 arg0) {
    if (arg0 < 0 || arg0 >= 4) {
        return 0;
    }
    return &D_0044ECD0[arg0 * 88];
}
