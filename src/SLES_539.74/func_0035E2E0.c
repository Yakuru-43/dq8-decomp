// range: 0x35E2E0 0x35E320
#include "common.h"

extern s32 D_0042CDB0 __attribute__((section(".data")));
extern s32 func_002989C0(s32 *);

s32 func_0035E2E0(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = func_002989C0(&D_0042CDB0);
    if (temp_v0 > 0) {
        return arg0[temp_v0 + 0x58];
    }
    return 0;
}
