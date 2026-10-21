// range: 0x25B760 0x25B910
#include "common.h"

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x3D];
    u8 closing;
    u8 pad4E[2];
    u8 open;
    u8 pad51[3];
    s32 readPos;
    s32 writePos;
    u8 pad5C[0x128 - 0x5C];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

s32 WaitSema(s32);
s32 SignalSema(s32);
s32 func_0025CCF0(Channel *);

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

inline s32 IsEmpty(Channel *ch) {
    return ch->open && ch->readPos == ch->writePos;
}

inline u8 IsBusy(Channel *ch) {
    s32 busy;

    if (ch == NULL) {
        return 0;
    }
    busy = 0;
    if (ch->sema > 0) {
        WaitSema(ch->sema);
    }
    if (ch->closing || !IsEmpty(ch)) {
        busy = 1;
    }
    if (ch->sema > 0) {
        SignalSema(ch->sema);
    }
    return busy ? busy != 0 : 0;
}

s32 func_0025B760(s32 id) {
    Channel *ch = GetChannel(id);

    if (ch == NULL) {
        return -2;
    }
    if (IsBusy(GetChannel(id))) {
        return -1;
    }
    return func_0025CCF0(ch);
}
