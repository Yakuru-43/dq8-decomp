// range: 0x162CA0 0x162D30
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
extern s32 D_003DFBA0;
extern s32 D_003E0308;
extern u8 D_003F27D0[];

s32 func_00162CA0(void) {
    s32 i;
    u8 *e;

    D_003E0308 = 0;
    if (PollSema(D_003DFBA0) < 0) {
        SignalSema(D_003DFBA0);
    }
    e = D_003F27D0;
    for (i = 0; i < 0x20; e += 0x128) {
        if (*(s32 *)(e + 0x120) != 0) {
            if (*(s32 *)(e + 4) == 0) {
                break;
            }
            if (*(s32 *)(e + 8) == 0) {
                break;
            }
        }
        i++;
    }
    return (i ^ 0x20) != 0;
}
