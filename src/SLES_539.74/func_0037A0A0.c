// range: 0x37A0A0 0x37A130
#include "common.h"

extern s8 D_003E1560;
extern s32 D_00409080 __attribute__((section(".data")));

extern void func_00309870(void *, s32);
extern s32 func_0037A130(s32 *);

s32 func_0037A0A0(s32 arg0) {
    if (arg0 != 0) {
        D_003E1560 = 0;
    }
    switch (D_003E1560) {
    case 0:
        func_00309870(&D_00409080, 3);
        D_003E1560 = D_003E1560 + 1;
        break;
    case 1:
        if (func_0037A130(&D_00409080) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
