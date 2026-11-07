// range: 0x00251290 0x00251480
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct Stream {
    u32 block;
    u8 *data;
    u32 size;
    volatile s32 sema; // thread-shared: the stream thread signals it
    volatile u32 writePos; // thread-shared: the ring is filled by the stream thread
    volatile u32 readPos;  // thread-shared
    u8 empty;
    u8 drained;
    u8 eof;
    u8 pad1B;
    u32 written;
    volatile u32 pos; // thread-shared: advanced by the stream thread
    volatile u32 end; // thread-shared: set by the stream thread
} Stream;

extern "C" {
void *func_00130FD0(void *dst, const void *src, u32 n);
s32 func_002514B0(u32 *offs, u32 *lens, u32 at, u32 n, u32 size);
u32 func_00251600(Stream *s, u32 n);
}

// bytes the ring holds
inline u32 Filled(Stream *s) {
    s32 n = s->writePos - s->readPos;

    if (n == 0 && s->empty) {
        return 0;
    }
    if (n <= 0) {
        n += s->size;
    }
    return n;
}

// copies up to `want` bytes out of the ring (fewer only at the end of the stream)
extern "C" u32 func_00251290(Stream *s, u8 *dst, u32 want) {
    u32 offs[2];
    u32 lens[2];
    s32 avail;
    u32 at;
    u32 size;
    s32 count;
    s32 i;
    u32 total;

    {
        SemaLock lock(&s->sema);

        avail = Filled(s);
        if (s->end != 0) {
            s32 left = s->end - s->pos;

            if (left < avail) {
                avail = left;
            }
        }
        at = s->readPos;
        size = s->size;
    }
    if (avail == 0 || (u32)avail < want) {
        SemaLock lock(&s->sema);

        if (!s->eof) {
            return 0;
        }
        want = avail;
    }
    count = func_002514B0(offs, lens, at, want, size);
    total = 0;
    for (i = 0; i < count; i++) {
        if (lens[i] != 0) {
            func_00130FD0(dst, s->data + offs[i], lens[i]);
            dst += lens[i];
            total += lens[i];
        }
    }
    func_00251600(s, total);
    return total;
}
