// range: 0x0025B3A0 0x0025B500
// flags: -Cpp_exceptions off
#include "common.h"
#include "stream_channel.h"

extern "C" s32 PollSema(s32 sema_id);
extern s32 D_003DFEA0;
extern s32 D_003E0C5C;

// func_0025BD50: signal the stream thread's semaphore unless it is already raised
inline void WakeStreamThread(void) {
    if (D_003E0C5C != 0) {
        return;
    }
    D_003E0C5C = 1;
    if (PollSema(D_003DFEA0) < 0) {
        SignalSema(D_003DFEA0);
    }
    D_003E0C5C = 0;
}

extern "C" s32 func_0025B3A0(s32 id) {
    Channel *ch = GetChannel(id);
    s32 queued;

    if (ch == NULL) {
        return -1;
    }
    queued = PushCommand(ch, 2);
    WakeStreamThread();
    return queued;
}
