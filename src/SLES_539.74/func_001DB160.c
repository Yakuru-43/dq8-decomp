// range: 0x1DB160 0x1DB1A0
#include "common.h"

extern char D_003A3400[] __attribute__((section(".data")));

char *func_001DB160(s32 arg0) {
    if (arg0 >= 0 && arg0 < 0x13C) {
        return &D_003A3400[arg0 * 0x10];
    }
    return 0;
}
