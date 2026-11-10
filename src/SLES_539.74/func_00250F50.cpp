// range: 0x00250F50 0x00250FB0
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x18];
    u8 f28;
} Stream;

extern "C" u8 func_00250F50(Stream *s) {
    SemaLock lock(&s->sema);

    return s->f28;
}
