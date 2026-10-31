// range: 0x163380 0x163430
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK TerminateThread(s32);                       /* extern */
M2C_UNK DeleteThread(s32);                          /* extern */
M2C_UNK DeleteSema(s32);                            /* extern */
void func_00117898(s32);                            /* extern */
extern s32 D_003DFB9C;
extern s32 D_003DFBA0;
extern s32 D_003DFBA4;
extern s32 D_003E02F8;
extern s32 D_003E02FC;
extern u32 D_003E0300;
extern s32 D_003E0308;

void func_00163380(void) {
    if (D_003E02F8 == 0) {
        return;
    }
    D_003E0308 = 1;
    D_003E02FC = 0;
    if (PollSema(D_003DFBA0) < 0) {
        SignalSema(D_003DFBA0);
    }
    WaitSema(D_003DFBA4);
    while ((0 < D_003E0300) ^ 1) {
        func_00117898(0xA);
    }
    TerminateThread(D_003DFB9C);
    DeleteThread(D_003DFB9C);
    DeleteSema(D_003DFBA0);
    DeleteSema(D_003DFBA4);
    D_003DFBA0 = -1;
    D_003DFB9C = -1;
}
