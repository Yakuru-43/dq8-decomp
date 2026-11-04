// range: 0x251A40 0x251B80
// flags: -flag divbyzerocheck
#include "common.h"

M2C_UNK SignalSema(s32); /* extern */
M2C_UNK WaitSema(s32);   /* extern */

/* Sema-guarded ring buffer (family of func_002510D0 / func_00251600). */
struct SemaRing {
    /* 0x00 */ u32 unit;
    /* 0x04 */ u32 pad04;
    /* 0x08 */ u32 size;
    /* 0x0C */ volatile s32 sema; // thread-shared: the reader waits on it
    /* 0x10 */ u32 rd;
    /* 0x14 */ u32 wr;
    /* 0x18 */ u8 full;
    /* 0x19 */ u8 pad19[3];
    /* 0x1C */ u32 out;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ u32 flush;
};

s32 func_00251A40(struct SemaRing *ring, s32 *countOut, s32 *sizeOut) {
    volatile s32 *id;
    u32 avail;
    s32 count;
    s32 room;

    id = &ring->sema;
    if (ring->sema > 0) {
        WaitSema(*id);
    }
    avail = ring->wr - ring->rd;
    if (avail == 0 && ring->full == 0) {
        count = 0;
    } else {
        if ((s32)avail <= 0) {
            avail += ring->size;
        }
        count = avail / ring->unit * ring->unit;
    }
    if (ring->flush != 0) {
        room = ring->flush - ring->out;
        if (room < 0) {
            room = 0;
        }
        if (room % ring->unit != 0) {
            count = ring->unit * (room / ring->unit + 1);
        }
        if (room < count) {
            count = room;
        }
    }
    *countOut = count;
    *sizeOut = ring->size;
    if (*id > 0) {
        SignalSema(*id);
    }
    return ring->rd;
}
