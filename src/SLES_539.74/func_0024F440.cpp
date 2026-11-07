// range: 0x0024F440 0x0024F4F0
// flags: -Cpp_exceptions off
#include "common.h"
#include "sema_lock.h"

typedef struct {
    u8 pad0[0x40];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad44[0x2C];
    f32 volume;
} Voice;

extern "C" void func_0024F440(Voice *v, f32 volume) {
    SemaLock lock(&v->sema);

    v->volume = volume;
    if (volume < 0.0f) {
        v->volume = 0.0f;
    }
    if (v->volume > 1.0f) {
        v->volume = 1.0f;
    }
}
