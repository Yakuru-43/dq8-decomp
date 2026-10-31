// range: 0x2B2440 0x2B24C0
#include "common.h"

void *func_001814D0(void);
s32 func_003089E0(void *, s32);

s32 func_002B2440(void) {
    if (func_003089E0((char *)func_001814D0() + 0x470, 0xB4) != 0) {
        return 0xC;
    }
    if (func_003089E0((char *)func_001814D0() + 0x470, 0xB2) != 0) {
        return 9;
    }
    return (func_003089E0((char *)func_001814D0() + 0x470, 0xAF)) ? 6 : 3;
}
