// range: 0x0025CCF0 0x0025CE70
// rodata: 0x3C9650 0x3C9674
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x3C];
    s8 state;
    u8 closing;
} Channel;

extern "C" s32 func_0025CCF0(Channel *ch) {
    SemaLock lock(&ch->sema);

    if (ch->closing) {
        return -1;
    }
    switch (ch->state) {
    case -1:
        return -2;
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
        return -1;
    case 4:
        return 1;
    case 5:
        return 2;
    case 7:
        return 4;
    default:
        return -2;
    }
}
