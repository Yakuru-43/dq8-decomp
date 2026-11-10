// range: 0x24FC80 0x24FD70
#include "common.h"

s32 PollSema(s32);
M2C_UNK SignalSema(s32);
M2C_UNK WaitSema(s32);

s32 func_0024FC80(u8 *arg0, u8 *arg1) {
    u32 flag;
    s32 v;
    s32 id;
    u32 ok;

top:
    v = *(volatile s32 *)(arg0 + 0x40);             // thread-shared
again:
    flag = 0;
    if (v > 0) {
        WaitSema(*(volatile s32 *)(arg0 + 0x40));   // thread-shared
    }
    if (*(u8 *)(arg0 + 0x45) != 0) {
        goto set1;
    }
    ok = (0 < (u32)*(u8 *)(arg0 + 0x48));
    if (ok != 0) {
        ok = ((*(u32 *)(arg0 + 0x4C) ^ *(u32 *)(arg0 + 0x50)) == 0);
    }
    if (ok == 0) {
        goto set1;
    }
    goto noflag;
set1:
    flag = 1;
noflag:
    if (*(volatile s32 *)(arg0 + 0x40) > 0) {       // thread-shared
        SignalSema(*(volatile s32 *)(arg0 + 0x40)); // thread-shared
    }
    if (flag == 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 0 < flag;
    }
    id = *(s32 *)(arg0 + 0x3C);
    if (id <= 0) {
        goto top;
    }
    if (PollSema(id) < 0) {
        SignalSema(*(volatile s32 *)(arg0 + 0x3C)); // thread-shared
        v = *(volatile s32 *)(arg0 + 0x40);         // thread-shared
        goto again;
    }
    goto top;
}
