// CLASS structural score=71 (69 words differ, 380 vs 388 bytes), -- -O3 (attempt 2).
// Attempt 1 (sema volatile, ready as two ifs): CLASS structural score=67 (396 vs 388).
// range: 0x24F640 0x24F7D0
#include "common.h"

extern "C" {

s32 SignalSema(s32);
s32 WaitSema(s32);
s32 PollSema(s32);

/* 16-slot byte queue guarded by the semaphores at 0x3C/0x40 */
typedef struct {
    /* 0x00 */ u8 pad00[0x3C];
    /* 0x3C */ s32 pollSema;
    /* 0x40 */ s32 sema;
    /* 0x44 */ u8 pad44;
    /* 0x45 */ u8 busy;
    /* 0x46 */ u8 pad46[2];
    /* 0x48 */ u8 full;
    /* 0x49 */ u8 pad49[3];
    /* 0x4C */ s32 rdIndex;
    /* 0x50 */ s32 wrIndex;
    /* 0x54 */ u8 slots[16];
} MsgQueue;

void func_0024F640(MsgQueue *queue) {
    bool written;

top:
    if (queue->sema > 0) {
        WaitSema(queue->sema);
    }
    if (queue->full != 0 || queue->rdIndex != queue->wrIndex) {
        written = true;
        queue->slots[queue->wrIndex] = 5;
        queue->wrIndex = (queue->wrIndex + 1) & 0xF;
        queue->full = 0;
    } else {
        written = false;
    }
    if (queue->sema > 0) {
        SignalSema(queue->sema);
    }
    if (written) {
        if (queue->pollSema > 0) {
            if (PollSema(queue->pollSema) < 0) {
                SignalSema(queue->pollSema);
            }
        }
    }
    if (written) {
        return;
    }
    while (1) {
        if (queue->sema > 0) {
            WaitSema(queue->sema);
        }
        written = false;
        if (queue->busy != 0 || !((u32)queue->full > 0 && queue->rdIndex == queue->wrIndex)) {
            written = true;
        }
        if (queue->sema > 0) {
            SignalSema(queue->sema);
        }
        if (!written) {
            goto top;
        }
        if (queue->pollSema > 0) {
            if (PollSema(queue->pollSema) < 0) {
                SignalSema(queue->pollSema);
            }
        }
    }
}

}
