// range: 0x162D30 0x162D70
// auto: m2c, verified byte-exact
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
extern s32 D_003DFBA0;
extern s32 D_003E0308;

void func_00162D30(void) {
    D_003E0308 = 0;
    if (PollSema(D_003DFBA0) < 0) {
        SignalSema(D_003DFBA0);
    }
}
