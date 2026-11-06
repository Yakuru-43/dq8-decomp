// range: 0x37A140 0x37A1E0
#include "common.h"

extern s8 D_003E155C;
extern s32 D_00409080 __attribute__((section(".data")));

extern M2C_UNK *func_00201C90(void);
extern s32 func_001FF770(void *);
extern void func_00309870(void *, s32);
extern s32 func_0037A130(s32 *);

s32 func_0037A140(s32 arg0) {
    func_001FF770(func_00201C90());
    if (arg0 != 0) {
        D_003E155C = 0;
        return 0;
    }
    switch (D_003E155C) {
    case 0:
        func_00309870(&D_00409080, 2);
        D_003E155C = D_003E155C + 1;
        break;
    case 1:
        if (func_0037A130(&D_00409080) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
