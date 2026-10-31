// range: 0x2B2400 0x2B2440
#include "common.h"

void *func_001814D0(void);
s32 func_003089E0(void *, s32);

s32 func_002B2400(void) {
    if (func_003089E0((char *)func_001814D0() + 0x470, 0xB4) != 0) {
        return 2;
    }
    return 1;
}
