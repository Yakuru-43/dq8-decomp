// range: 0x305FC0 0x306030
#include "common.h"

extern s32 D_003DFF80;
extern s32 D_003DFF84;
extern s32 D_003E113C;

s32 PollSema(s32);
s32 WaitSema(s32);

s32 func_00305FC0(s32 wait) {
    if (D_003E113C != 0) {
        return 0;
    }
    if (D_003DFF80 < 0 || D_003DFF84 < 0) {
        return 0;
    }
    if (wait == 0) {
        return PollSema(D_003DFF84) < 0;
    }
    WaitSema(D_003DFF84);
    D_003E113C = 1;
    return 0;
}
