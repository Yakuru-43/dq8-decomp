// CLASS structural score=77 (76 words differ, 336 vs 332 bytes), -- -O3
// Attempt 1 below was the best. Attempt 2 (`volatile s32 * volatile sema`,
// score 89, 352 bytes) blew the frame up; the plain local was closer.
// range: 0x24F4F0 0x24F640
#include "common.h"

extern "C" {

s32 SignalSema(s32);
s32 WaitSema(s32);
s32 PollSema(s32);

/* 16-slot byte queue guarded by the semaphores at 0x3C/0x40 */
typedef struct {
    /* 0x00 */ u8 pad00[0x3C];
    /* 0x3C */ s32 pollSema;
    /* 0x40 */ volatile s32 sema; // thread-shared: the reader signals it
    /* 0x44 */ u8 pad44[4];
    /* 0x48 */ u8 full;
    /* 0x49 */ u8 pad49[3];
    /* 0x4C */ s32 rdIndex;
    /* 0x50 */ s32 wrIndex;
    /* 0x54 */ u8 slots[16];
    /* 0x64 */ u8 pad64[4];
    /* 0x68 */ volatile s32 count; // thread-shared: the reader drains it
} MsgQueue;

s32 func_0024F4F0(MsgQueue *queue) {
    volatile s32 *sema = &queue->sema;
    bool written;

    if (queue->sema > 0) {
        WaitSema(*sema);
    }
    if (queue->count > 0) {
        if (*sema > 0) {
            SignalSema(*sema);
        }
        return 0;
    }
    queue->count = queue->count + 1;
    if (*sema > 0) {
        SignalSema(*sema);
    }
    if (queue->sema > 0) {
        WaitSema(queue->sema);
    }
    if (queue->full == 0 && queue->rdIndex == queue->wrIndex) {
        written = false;
    } else {
        queue->slots[queue->wrIndex] = 4;
        queue->wrIndex = (queue->wrIndex + 1) & 0xF;
        queue->full = 0;
        written = true;
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
    return written;
}

}
