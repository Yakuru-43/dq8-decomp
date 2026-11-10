// range: 0x251950 0x251A40
#include "common.h"

M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK SignalSema(s32);                            /* extern */

typedef struct RingBuf {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 size;
    /* 0x0C */ s32 semid;
    /* 0x10 */ s32 tail;
    /* 0x14 */ s32 head;
    /* 0x18 */ u8 full;
    /* 0x19 */ u8 pad19[7];
    /* 0x20 */ s32 cap_lo;
    /* 0x24 */ s32 cap_hi;
} RingBuf;

s32 func_00251950(RingBuf *ring, s32 *arg1, s32 *arg2) {
    s32 *sema;
    s32 diff;
    s32 lim;
    s32 ret;

    sema = &ring->semid;
    if (*sema > 0) {
        WaitSema(*sema);
    }
    diff = ring->tail - ring->head;
    if (diff == 0) {
        if (ring->full != 0) {
            diff = 0;
            goto have_diff;
        }
    }
    if (diff <= 0) {
        diff += ring->size;
    }
have_diff:
    if (ring->cap_hi != 0) {
        lim = ring->cap_hi - ring->cap_lo;
        if (lim < diff) {
            diff = lim;
        }
    }
    *arg1 = diff;
    *arg2 = ring->size;
    ret = ring->head;
    if (*sema > 0) {
        SignalSema(*sema);
    }
    return ret;
}
