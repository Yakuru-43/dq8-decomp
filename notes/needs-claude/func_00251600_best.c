// range: 0x251600 0x2517D0
// flags: -flag divbyzerocheck
#include "common.h"

M2C_UNK SignalSema(s32); /* extern */
M2C_UNK WaitSema(s32);   /* extern */

/* Sema-guarded ring buffer (family of func_002510D0 / func_00251590). */
struct SemaRing {
    /* 0x00 */ s32 unit;
    /* 0x04 */ s32 pad04;
    /* 0x08 */ s32 size;
    /* 0x0C */ volatile s32 sema;
    /* 0x10 */ s32 mark;
    /* 0x14 */ s32 wr;
    /* 0x18 */ u8 full;
    /* 0x19 */ u8 flag19;
    /* 0x1A */ u8 flag1A;
    /* 0x1B */ u8 pad1B[5];
    /* 0x20 */ s32 out;
    /* 0x24 */ s32 flush;
};

static inline volatile s32 *SemaId(struct SemaRing *ring) {
    return &ring->sema;
}

s32 func_00251600(struct SemaRing *ring, s32 n) {
    s32 avail;
    s32 room;

    if (n == 0) {
        return 0;
    }
    if (ring->sema > 0) {
        WaitSema(*SemaId(ring));
    }
    avail = ring->mark - ring->wr;
    if (avail == 0 && ring->full) {
        /* ring full: no room */
    } else if (avail <= 0) {
        avail += ring->size;
    }
    if (ring->flush != 0) {
        room = ring->flush - ring->out;
        if (room < avail) {
            avail = room;
        }
    }
    if (avail < n) {
        if (*SemaId(ring) > 0) {
            SignalSema(*SemaId(ring));
        }
        return 0;
    }
    ring->wr = (ring->wr + n) % ring->size;
    ring->out += n;
    if (ring->flush != 0 && ring->out >= ring->flush) {
        if (ring->wr % ring->unit != 0) {
            ring->out = ring->flush;
            ring->wr = (ring->unit * (ring->wr / ring->unit + 1)) % ring->size;
        }
    }
    if (ring->wr == ring->mark) {
        ring->full = 1;
        if (ring->flag1A != 0) {
            ring->flag19 = 1;
        }
    }
    if (*SemaId(ring) > 0) {
        SignalSema(*SemaId(ring));
    }
    return n;
}
