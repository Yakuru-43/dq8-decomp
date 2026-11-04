// range: 0x1886B0 0x1887D0
#include "common.h"

extern "C" {

extern f32 D_003DF6D4;

struct Clock {
    u8 pad1[0x6B0C];
    s32 count;
    f32 time;
    f32 rate;
    s32 active;
    f32 GetTime() const;
};

inline f32 Clock::GetTime() const {
    return time;
}

void func_001886B0(Clock *timer, f32 mult) {
    f32 speed;
    f32 t;
    s32 mode;
    f32 scale;
    f32 eff;
    f32 next;
    f32 q;
    f32 rem;

    if (timer->active == 0) {
        return;
    }
    speed = timer->rate * mult;
    scale = 1.0f;
    mode = 0;
    t = timer->time;
    if (18.0f <= t || t < 1.0f) {
        mode = 1;
    } else if (1.0f <= t && t < 6.0f) {
        mode = 2;
    }
    if (mode != 0) {
        scale = 1.5f;
    }
    eff = speed * scale;
    next = eff + t;
    q = (f32)(s32)(next / 24.0f);
    rem = next - q * 24.0f;
    if (rem < 0.0f) {
        rem += 24.0f;
    }
    timer->time = rem;
    if (t > 24.0f - eff - D_003DF6D4) {
        if (timer->GetTime() < D_003DF6D4 + eff) {
            timer->count = timer->count + 1;
        }
    }
}

}
