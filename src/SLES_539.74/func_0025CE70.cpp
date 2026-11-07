// range: 0x0025CE70 0x0025D050
// flags: -Cpp_exceptions off
#include "common.h"
#include "stream_channel.h"

extern const f32 D_003DF3AC __attribute__((section(".sdata"))); // 1/60 s
extern s8 D_003DFE98;

// queues the "parameters changed" command; the caller holds the lock
inline bool QueueParamsCommand(Channel *ch) {
    bool queued;

    if (ch->empty == 0 && ch->readPos == ch->writePos) {
        queued = false;
    } else {
        ch->cmds[ch->writePos] = D_003DFE98;
        ch->writePos = (ch->writePos + 1) % 24;
        queued = true;
        ch->empty = 0;
    }
    return queued;
}

extern "C" bool func_0025CE70(Channel *ch, f32 a, f32 b, f32 c, f32 d) {
    if (a < D_003DF3AC) {
        return false;
    }
    SemaLock lock(&ch->sema);
    if (!PushParams(ch, a, b, c, d)) {
        return false;
    }
    if (!QueueParamsCommand(ch)) {
        PopParams(ch);
        return false;
    }
    return true;
}
