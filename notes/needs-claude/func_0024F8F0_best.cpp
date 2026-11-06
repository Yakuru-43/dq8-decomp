// range: 0x24F8F0 0x24F9D0
#include "common.h"

extern "C" {

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(void *);                         /* extern */
M2C_UNK WaitSema(void *);                           /* extern */

bool func_0024F8F0(u8 *arg0) {
    bool ret;

    if (*(s32 *)(arg0 + 0x40) > 0) {
        WaitSema(*(void **)(arg0 + 0x40));
    }
    if (*(u8 *)(arg0 + 0x48) != 0 ||
        *(s32 *)(arg0 + 0x4C) != *(s32 *)(arg0 + 0x50)) {
        arg0[0x54 + *(s32 *)(arg0 + 0x50)] = 2;
        *(s32 *)(arg0 + 0x50) = (*(s32 *)(arg0 + 0x50) + 1) & 0xF;
        arg0[0x48] = 0;
        ret = true;
    } else {
        ret = false;
    }
    if (*(s32 *)(arg0 + 0x40) > 0) {
        SignalSema(*(void **)(arg0 + 0x40));
    }
    if (ret) {
        if (*(s32 *)(arg0 + 0x3C) > 0) {
            if (PollSema(*(s32 *)(arg0 + 0x3C)) < 0) {
                SignalSema(*(void **)(arg0 + 0x3C));
            }
        }
    }
    return ret;
}

}
