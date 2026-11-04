// CLASS structural score=74 (72 words differ, 296 vs 288 bytes), best attempt 2, `-- -O3`
// Attempt 1 (non-volatile sema): same score, but CW CSE'd every sema guard into ONE
// load reused as test and arg in $a0 (mine `lw $a0,0x40($s1); bgtz $a0`), guards 2-4
// inverted to cold blocks. volatile sema (below) is strictly better: guards 1/3/4 then
// emit the original's `lw $v0,0x40($s1); bgtzl $v0,cold; lw $a0,0x40($s1)` double load
// with delay-slot arg exactly, and guard 2 goes through the v1/s0 pointer.
// Attempt 3 = attempt 2 with `bool` return type: identical score, the return `andi
// $v0,$s0,0xFF` is still there.
// range: 0x24F7D0 0x24F8F0
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
    /* 0x64 */ u8 pad64[0x78 - 0x64];
    /* 0x78 */ s32 lastValue;
} MsgQueue;

s32 func_0024F7D0(MsgQueue *queue, s32 value) {
    volatile s32 *sema = &queue->sema;
    bool written;

    if (queue->sema > 0) {
        WaitSema(*sema);
    }
    queue->lastValue = value;
    if (*sema > 0) {
        SignalSema(*sema);
    }
    if (queue->sema > 0) {
        WaitSema(queue->sema);
    }
    if (queue->full != 0 || queue->rdIndex != queue->wrIndex) {
        written = true;
        queue->slots[queue->wrIndex] = 3;
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
    return written;
}

}
