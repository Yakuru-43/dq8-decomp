// range: 0x302360 0x3026A0
// best draft for func_00302360, try_match score 196 (structural).
// Prologue/epilogue word-exact; float register allocation diverges from
// +0x30 (mine arg5->f22 arg6->f21 rate1->f20; orig arg5->f21 arg6->f20
// rate1->f23 rate2->f22). See notes/needs-claude/func_00302360.md.
#include "common.h"

s32 func_00302140(s32 *, s32, s32, s32 *);      /* extern */
char *func_00181420(s32);                        /* extern */
s32 func_00204AB0(char *, s32, s32);             /* extern */
f32 func_0013BC60(void);                         /* extern */
f32 func_0013B9C0(void);                         /* extern */
extern f32 D_003DF6EC;
extern f32 D_003DFAF8;

s32 func_00302360(s32 *obj, s32 key, s32 idx, s32 bit, s32 flags, f32 arg5,
                  f32 arg6) {
    s32 mgr;
    s32 arr;
    s32 slot;
    s32 raw;
    s32 byte;
    s32 d;
    f32 rate1;
    f32 rate2;
    f32 f;
    f32 g;
    f32 h;
    f32 t;
    f32 *timer;

    if (key == 0) {
        return 0;
    }
    func_00302140(obj, key, bit, &slot);
    mgr = obj[1];
    if (mgr == 0) {
        return 0;
    }
    arr = obj[4];
    if (arr == 0) {
        return 0;
    }
    raw = (s32)*(u16 *)(arr + ((s32)*(u8 *)(mgr + (slot << 6) + 2) << 1) + 0x18);
    if (raw >= 0) {
        rate1 = (f32)raw;
    } else {
        rate1 = (f32)((raw >> 1) | (raw & 1));
        rate1 = rate1 + rate1;
    }
    rate1 = rate1 / 256.0f;
    raw = (s32)*(u16 *)(arr + (idx << 1));
    if (raw >= 0) {
        rate2 = (f32)raw;
    } else {
        rate2 = (f32)((raw >> 1) | (raw & 1));
        rate2 = rate2 + rate2;
    }
    rate2 = rate2 / 256.0f;
    if ((flags & 1) != 0 || (flags & 8) != 0) {
        byte = *(u8 *)(mgr + (slot << 6));
        d = func_00204AB0(func_00181420(mgr + (slot << 6)), 0, 1) - byte;
        if (byte < 51) {
            if (d >= 3) {
                rate2 = 0.0f;
            } else if (d >= -2) {
                rate2 = rate2 * 0.5f;
            }
        } else {
            if (d >= 3) {
                rate2 = rate2 * 0.25f;
            } else if (d >= -2) {
                rate2 = rate2 * 0.5f;
            }
        }
    }
    if (arg5 < 0.0f) {
        arg5 = -arg5;
    }
    f = rate2 * rate1;
    f = arg6 * f;
    g = arg5 * D_003DF6EC;
    h = (f32)obj[12] / 100.0f;
    f = g * f;
    f = f * h;
    timer = (f32 *)obj;
    t = timer[9] - f;
    timer[9] = t;
    if (t <= 0.0f) {
        timer[11] = timer[10];
        if ((flags & 2) != 0) {
            if (func_0013BC60() < 0.5f) {
                if (obj[1] == 0 || obj[4] == 0) {
                    obj[9] = 0x42480000; /* 50.0f */
                } else {
                    t = D_003DFAF8 * (6.0f + func_0013B9C0());
                    if (t < 5.0f) {
                        t = 5.0f;
                    }
                    timer[9] = t * *(f32 *)((char *)obj[4] + 0x48);
                }
                timer[10] = timer[9];
            }
        }
    }
    if (obj[1] == 0) {
        return 0;
    }
    if (obj[4] == 0) {
        return 0;
    }
    if (timer[9] <= 0.0f) {
        return 1;
    }
    return 0;
}
