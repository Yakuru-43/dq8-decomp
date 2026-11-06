// range: 0x251020 0x2510D0
// flags: -flag divbyzerocheck
#include "common.h"

M2C_UNK WaitSema(s32);                                /* extern */
M2C_UNK SignalSema(s32);                              /* extern */

typedef struct {
    /* 0x00 */ u32 size;
    /* 0x04 */ u8 pad_4[8];
    /* 0x0C */ volatile s32 sema;   // thread-shared
    /* 0x10 */ u8 pad_10[24];
    /* 0x28 */ u8 busy;
    /* 0x2C */ u32 start;
    /* 0x30 */ u32 rest;
} Buf;

/* Best attempt 2026-11-06 (factory-2): CLASS structural score=35.
   First test via buf->sema, calls and second test via *sema. */
void func_00251020(Buf *buf, u32 index) {
    volatile s32 *sema = &buf->sema;

    if (buf->sema > 0) {
        WaitSema(*sema);
    }
    buf->busy = 1;
    buf->start = (index / buf->size) * buf->size;
    buf->rest = index % buf->size;
    if (*sema > 0) {
        SignalSema(*sema);
    }
}
