// range: 0x25BD50 0x25BDA0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
extern s32 D_003DFEA0;
extern s32 D_003E0C5C;

void func_0025BD50(void) {

    if (!(D_003E0C5C == 0)) {
        return;
    }

    D_003E0C5C = 1;
    if (PollSema(D_003DFEA0) < 0) {
        SignalSema(D_003DFEA0);
    }
    D_003E0C5C = 0;
}
