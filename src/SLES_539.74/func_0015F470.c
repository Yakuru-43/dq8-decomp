// range: 0x15F470 0x15F490
#include "common.h"

extern char *D_003E0298;

s32 func_0015F470(void) {
    if (D_003E0298 != 0) {
        return *(s32 *)(D_003E0298 + 0xF20);
    }
    return 0;
}
