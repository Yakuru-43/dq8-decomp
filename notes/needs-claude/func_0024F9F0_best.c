// range: 0x24F9F0 0x24FAC0
#include "common.h"

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */

s32 func_0024F9F0(u8 *arg0) {
    s32 flag;
    s32 v;
    s32 id;
    s32 ok;

top:
    v = *(volatile s32 *)(arg0 + 0x40);             // thread-shared
again:
    flag = 0;
    if (v > 0) {
        WaitSema(*(volatile s32 *)(arg0 + 0x40));   // thread-shared
    }
    if (*(u8 *)(arg0 + 0x45) != 0) {
        flag = 1;
    } else {
        ok = (0 < *(u8 *)(arg0 + 0x48));
        if (ok != 0) {
            ok = ((*(s32 *)(arg0 + 0x4C) ^ *(s32 *)(arg0 + 0x50)) == 0);
        }
        if (ok == 0) {
            flag = 1;
        }
    }
    if (*(volatile s32 *)(arg0 + 0x40) > 0) {       // thread-shared
        SignalSema(*(volatile s32 *)(arg0 + 0x40)); // thread-shared
    }
    if (flag == 0) {
        return *(s32 *)(arg0 + 0x6C);
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
