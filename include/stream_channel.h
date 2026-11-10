#ifndef STREAM_CHANNEL_H
#define STREAM_CHANNEL_H

// C++ only: the six sound stream channels (D_0041CBC0) and their command queue.
#include "sema_lock.h"

typedef struct ParamSet {
    f32 v[4];
} ParamSet;

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    char *name;
    s8 f14;
    u8 pad15[0x37];
    s8 state;
    u8 closing;
    u8 pad4E[2];
    u8 empty; // the command queue: a ring of 24, full when !empty && readPos == writePos
    u8 pad51[3];
    u32 readPos;
    u32 writePos;
    u8 cmds[24];
    u8 pad74[8];
    u8 paramEmpty; // a ring of 4 parameter sets, same scheme
    u8 pad7D[3];
    u32 paramRead;
    u32 paramWrite;
    ParamSet params[4];
    u8 padC8[0x128 - 0xC8];
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

// queues `cmd` unless the queue is full; true if it was queued
inline bool PushCommand(Channel *ch, u8 cmd) {
    SemaLock lock(&ch->sema);
    bool queued;

    if (ch->empty == 0 && ch->readPos == ch->writePos) {
        queued = false;
    } else {
        ch->cmds[ch->writePos] = cmd;
        ch->writePos = (ch->writePos + 1) % 24;
        queued = true;
        ch->empty = 0;
    }
    return queued;
}

// queues a parameter set unless the ring is full; true if it was queued
inline bool PushParams(Channel *ch, f32 a, f32 b, f32 c, f32 d) {
    bool queued;

    if (ch->paramEmpty == 0 && ch->paramRead == ch->paramWrite) {
        queued = false;
    } else {
        u32 w = ch->paramWrite;
        ch->params[w].v[0] = a;
        ch->params[w].v[1] = d;
        ch->params[w].v[2] = c;
        ch->params[w].v[3] = b;
        ch->paramWrite = (ch->paramWrite + 1) & 3;
        queued = true;
        ch->paramEmpty = 0;
    }
    return queued;
}

// drops the oldest parameter set; false if there was none
inline bool PopParams(Channel *ch) {
    if (ch->paramEmpty && ch->paramRead == ch->paramWrite) {
        return false;
    }
    ch->paramRead = (ch->paramRead + 1) & 3;
    if (ch->paramRead == ch->paramWrite) {
        ch->paramEmpty = 1;
    }
    return true;
}

#endif
