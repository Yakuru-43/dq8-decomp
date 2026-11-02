// range: 0x162BC0 0x162CA0
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
void func_001627E0(s32);
extern s32 D_003DFBA0;
extern s32 D_003DFBA4;
extern s32 D_003E02EC;
extern s32 D_003E02F0;
extern s32 D_003E02F4;
extern s32 D_003E0308;
extern u8 D_003F27D0[];

void func_00162BC0(void) {
    u8 *e;
    s32 i;
    s32 temp_v1;
    s32 var_a2;

    D_003E0308 = 1;
    if (PollSema(D_003DFBA0) < 0) {
        SignalSema(D_003DFBA0);
    }
    WaitSema(D_003DFBA4);
    e = D_003F27D0;
    for (i = 0; i < 0x20; i++, e += 0x128) {
        if (*(s32 *)(e + 0x120) != 0 && *(s32 *)(e + 8) == 0) {
            func_001627E0(*(s32 *)(e + 0x124));
            *(s32 *)(e + 0x124) = -1;
        }
    }
    var_a2 = 0;
    do {
        temp_v1 = var_a2 * 0x128;
        var_a2 += 1;
        *(s32 *)(D_003F27D0 + temp_v1 + 0x120) = 0;
    } while (var_a2 < 0x20);
    D_003E02F4 = 0;
    D_003E02F0 = -1;
    D_003E02EC = 0;
}
