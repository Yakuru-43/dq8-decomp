// range: 0x251C40 0x251D60
#include "common.h"

M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
extern void FlushCache(s32);
M2C_UNK sceSifSetDma(M2C_UNK *, s32);               /* extern */
M2C_UNK sceSifDmaStat(s32);                         /* extern */
M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
M2C_UNK func_00117898(s32);                         /* extern */
extern s32 D_003E0BB4;
extern M2C_UNK D_003C8F10 __attribute__((section(".data")));
extern M2C_UNK D_003C8F30 __attribute__((section(".data")));

s32 func_00251C40(s32 arg0, s32 arg1, s32 arg2) {
    s32 dmas[4];
    s32 id;

    if (arg2 != 0) {
        WaitSema(D_003E0BB4);
        if (arg0 % 16 != 0) {
            DebugPrintf(&D_003C8F10);
        }
        if ((arg2 % 4 != 0) || ((arg1 & 3) != 0)) {
            DebugPrintf(&D_003C8F30);
        }
        dmas[0] = arg0;
        dmas[1] = arg1;
        dmas[2] = arg2;
        dmas[3] = 0;
        FlushCache(0);
        id = sceSifSetDma(dmas, 1);
        if (id != 0) {
            while (sceSifDmaStat(id) >= 0) {
                func_00117898(10);
            }
            id = 0;
        } else {
            id = -1;
        }
        SignalSema(D_003E0BB4);
        return id;
    }
    return 0;
}
