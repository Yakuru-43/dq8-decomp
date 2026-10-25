// range: 0x2C70D0 0x2C7140
// rodata: 0x3CD4D0 0x3CD4E8
#include "common.h"

extern char D_00421AD0[] __attribute__((section(".data")));
extern s32 *func_00359CF0(char *, s32);

s32 func_002C70D0(void) {
    s32 *p = func_00359CF0(D_00421AD0, 0x80);
    if (p == NULL) {
        return 0;
    }
    switch (*p) {
    case 0x1B9:
    case 0x1BA:
    case 0x1BB:
    case 0x1BC:
    case 0x1BD:
    case 0x1BE:
        return 1;
    }
    return 0;
}
