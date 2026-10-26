// range: 0x13B510 0x13B5B0
#include "common.h"

struct DoubleParts {
    /* 0x00 */ s32 kind;
    /* 0x04 */ s32 sign;
    /* 0x08 */ s32 exp;
    /* 0x0C */ s32 pad;
    /* 0x10 */ u64 mantissa;
    /* 0x18 */ u32 tail[2];
};

extern void func_0013AA18(f64 *d, struct DoubleParts *parts);

s32 func_0013B510(f64 d) {
    struct DoubleParts parts;
    struct DoubleParts *pp = &parts;

    func_0013AA18(&d, pp);
    if (parts.kind == 2) {
        return 0;
    }
    if (parts.kind < 2) {
        return 0;
    }
    if (parts.sign != 0) {
        return 0;
    }
    if (parts.kind == 4) {
        return -1;
    }
    if (parts.exp < 0) {
        return 0;
    }
    if (parts.exp >= 32) {
        return -1;
    }
    if (parts.exp < 61) {
        return (s32)(parts.mantissa >> (60 - parts.exp));
    }
    return (s32)(parts.mantissa << (parts.exp - 60));
}
