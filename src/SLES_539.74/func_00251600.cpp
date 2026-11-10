// range: 0x00251600 0x002517D0
// flags: -Cpp_exceptions off -flag divbyzerocheck
#include "common.h"
#include "sema_lock.h"

typedef struct Stream {
    u32 block;
    u8 pad4[4];
    u32 size;
    volatile s32 sema; // thread-shared: the stream thread signals it
    volatile u32 writePos; // thread-shared: the ring is read by the stream thread
    volatile u32 readPos;  // thread-shared
    u8 empty;
    u8 drained;
    u8 eof;
    u8 pad1B;
    u32 written;
    volatile u32 pos; // thread-shared: advanced by the stream thread
    volatile u32 end; // thread-shared: set by the stream thread
} Stream;

// bytes the ring holds
inline u32 Filled(Stream *s) {
    u32 n = s->writePos - s->readPos;

    if (n == 0 && s->empty) {
        return 0;
    }
    if ((s32)n <= 0) {
        n += s->size;
    }
    return n;
}

// consumes `n` bytes at readPos; returns n, or 0 if the ring holds fewer
extern "C" u32 func_00251600(Stream *s, u32 n) {
    s32 avail;

    if (n == 0) {
        return 0;
    }
    SemaLock lock(&s->sema);
    avail = Filled(s);
    if (s->end != 0) {
        s32 left = s->end - s->pos;

        if (left < avail) {
            avail = left;
        }
    }
    if ((u32)avail < n) {
        return 0;
    }
    s->readPos = (s->readPos + n) % s->size;
    s->pos += n;
    if (s->end != 0 && s->pos >= s->end && s->readPos % s->block != 0) {
        s->pos = s->end;
        s->readPos = (s->readPos / s->block + 1) * s->block % s->size;
    }
    if (s->readPos == s->writePos) {
        s->empty = 1;
        if (s->eof) {
            s->drained = 1;
        }
    }
    return n;
}
