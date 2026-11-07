// range: 0x0024F4F0 0x0024F640
// flags: -Cpp_exceptions off
#include "common.h"
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
    u8 pad64[4];
    volatile s32 users; // thread-shared: the sound thread counts down
    u8 pad6C[4];
    f32 volume;
} Voice;

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

extern "C" bool func_0024F4F0(Voice *v) {
    {
        SemaLock lock(&v->sema);

        if (v->users > 0) {
            return false;
        }
        v->users++;
    }
    return PushVoiceCommand(v, 4);
}
