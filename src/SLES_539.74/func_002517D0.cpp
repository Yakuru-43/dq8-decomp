// range: 0x002517D0 0x00251950
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
    u8 pad19[3];
    u32 written;
    u32 pos;
    volatile u32 end; // thread-shared: set by the stream thread
} Stream;

// whole blocks the ring has room for
inline u32 FreeBlocks(Stream *s) {
    u32 n = s->readPos - s->writePos;

    if (n == 0 && !s->empty) {
        return 0;
    }
    if ((s32)n <= 0) {
        n += s->size;
    }
    return n / s->block * s->block;
}

// commits `n` bytes written at writePos; returns n, or 0 if they don't fit
extern "C" u32 func_002517D0(Stream *s, u32 n) {
    s32 room;

    if (n == 0) {
        return 0;
    }
    SemaLock lock(&s->sema);
    room = FreeBlocks(s);
    if (s->end != 0) {
        s32 left = s->end - s->written;

        if (left < 0) {
            left = 0;
        }
        if (left % s->block != 0) {
            left = (left / s->block + 1) * s->block;
        }
        if (left < room) {
            room = left;
        }
    }
    if ((u32)room < n) {
        return 0;
    }
    s->writePos = (s->writePos + n) % s->size;
    s->written += n;
    s->empty = 0;
    return n;
}
