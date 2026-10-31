// range: 0x350EA0 0x350ED0
#include "common.h"

s32 func_003515A0(void);
extern s32 D_003E1374;

s32 func_00350EA0(void) {
    s32 temp_v0;

    temp_v0 = func_003515A0();
    if (temp_v0 == 0) {
        return 0;
    }
    return D_003E1374 + 0x250;
}
