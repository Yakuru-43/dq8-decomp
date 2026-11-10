#ifndef SOUND_VOICE_H
#define SOUND_VOICE_H

// C++ only: a sound voice with its locked 16-slot command ring (game_24F440..24F9F0).
#include "sema_lock.h"

extern "C" s32 PollSema(s32 sema_id);

typedef struct Voice {
    u8 pad0[0x3C];
    s32 wakeSema;
    volatile s32 sema; // thread-shared: the sound thread signals it
    u8 pad44[4];
    u8 empty; // a ring of 16 commands, full when !empty && readPos == writePos
    u8 pad49[3];
    u32 readPos;
    u32 writePos;
    u8 cmds[16];
    char *name;
    volatile s32 users; // thread-shared: the sound thread counts down
    u8 pad6C[4];
    f32 volume;
} Voice;

// queues `cmd` unless the ring is full, then wakes the sound thread; true if queued
inline bool PushVoiceCommand(Voice *v, u8 cmd) {
    bool queued;

    if (v->sema > 0) {
        WaitSema(v->sema);
    }
    if (v->empty == 0 && v->readPos == v->writePos) {
        queued = false;
    } else {
        queued = true;
        v->cmds[v->writePos] = cmd;
        v->writePos = (v->writePos + 1) & 0xF;
        v->empty = 0;
    }
    if (v->sema > 0) {
        SignalSema(v->sema);
    }
    if (queued && v->wakeSema > 0 && PollSema(v->wakeSema) < 0) {
        SignalSema(v->wakeSema);
    }
    return queued;
}

#endif
