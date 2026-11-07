// range: 0x0025B270 0x0025B3A0
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x40];
    u8 pending;
    u8 pad51[3];
    u32 readPos;
    u32 writePos;
    u8 cmds[24];
    u8 pad74[0x128 - 0x74];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

inline Channel *GetChannel(s32 id) {
    Channel *ch;

    if (id >= 0 && id < 6) {
        ch = &D_0041CBC0[id];
    } else {
        ch = NULL;
    }
    if (ch == NULL || D_0041D2B0[id] == 0) {
        ch = NULL;
    }
    return ch;
}

// queues `cmd` unless the channel is idle; 1 if it was queued
inline bool PushCommand(Channel *ch, u8 cmd) {
    SemaLock lock(&ch->sema);
    bool queued;

    if (ch->pending == 0 && ch->readPos == ch->writePos) {
        queued = false;
    } else {
        ch->cmds[ch->writePos] = cmd;
        ch->writePos = (ch->writePos + 1) % 24;
        queued = true;
        ch->pending = 0;
    }
    return queued;
}

extern "C" s32 func_0025B270(s32 id) {
    Channel *ch = GetChannel(id);

    if (ch == NULL) {
        return -1;
    }
    return PushCommand(ch, 3);
}
