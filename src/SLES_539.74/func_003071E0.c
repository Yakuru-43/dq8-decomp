// range: 0x3071E0 0x307220
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00308B50(s32, s32);                         /* extern */

s32 func_003071E0(void) {
    s32 unk;

    unk = func_00308B50(func_001814D0() + 0x470, 0xB);
    if (4 <= unk) {
        return 0x25;
    }
    return 5;
}
