// range: 0x00250DD0 0x00250F50
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct Stream {
    u8 pad0[0x8];
    u32 size;
    volatile s32 sema; // thread-shared: the stream thread signals it
    u32 writePos;
    u32 readPos;
    u8 full;
    u8 pad19[7];
    volatile u32 pos; // thread-shared: advanced by the stream thread
    volatile u32 end; // thread-shared: set by the stream thread
    u8 active;
    u8 pad29[3];
    u32 next;
    u32 want;
} Stream;

extern "C" void func_00251600(Stream *s, u32 n);

inline bool IsDrained(Stream *s) {
    SemaLock lock(&s->sema);

    if (s->end == 0) {
        return false;
    }
    return s->pos >= s->end;
}

// bytes the ring holds
inline u32 Filled(Stream *s) {
    s32 n = s->writePos - s->readPos;

    if (n == 0 && s->full) {
        return 0;
    }
    if (n <= 0) {
        n += s->size;
    }
    return n;
}

extern "C" bool func_00250DD0(Stream *s) {
    u32 n;

    if (!s->active) {
        return false;
    }
    if (!IsDrained(s)) {
        return false;
    }
    {
        SemaLock lock(&s->sema);

        if (s->want != 0 && Filled(s) < s->want) {
            return false;
        }
        s->pos = s->next;
        n = s->want;
    }
    if (n != 0) {
        func_00251600(s, n);
    }
    return true;
}
