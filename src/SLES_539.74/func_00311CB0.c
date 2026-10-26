// range: 0x311CB0 0x311D60
#include "common.h"

struct NotifyMsg {
    char pad0[4];
    s32 field4;
    char pad8[8];
    s32 field10;
    s32 field14;
    s32 field18;
};

extern s8 D_003E1184;
extern s8 D_003E1188;
extern s8 D_003E118C;
extern s8 D_003E1190;
extern s8 D_003E1194;

struct NotifyMsg *func_001813D0(void);
s32 func_00311D60(void *, s8, s8, s8, s8, s32, s32);

s32 func_00311CB0(s32 arg0, void *arg1, s32 arg2) {
    struct NotifyMsg *msg;

    D_003E1184 = arg0;
    msg = func_001813D0();
    if (msg != 0 && arg0 == 0) {
        D_003E1188 = msg->field10;
        D_003E118C = msg->field14;
        D_003E1190 = msg->field4;
        D_003E1194 = msg->field18;
    } else {
        D_003E1190 = 0;
        D_003E1188 = 5;
        D_003E118C = 5;
        D_003E1194 = 5;
    }
    return func_00311D60(arg1, D_003E1188, D_003E118C, D_003E1194, D_003E1190,
                         arg2, 0x2000042);
}
