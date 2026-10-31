// range: 0x108090 0x1080E0
// Replace-from-front through the six-argument splice worker: position 0,
// the string's own length, the caller's two trailing arguments and the
// worker's flag byte, left to the worker.
#include "common.h"

extern "C" {

extern void func_00107100(void *, u32, u32, u32, u32, s8);

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

struct ShortByte {
    /* 0x00 */ u8 tag : 1;
    /* 0x01 */ u8 len : 7;
};

void func_00108090(struct Str *s, u32 tail, u32 guard) {
    u8 flag[4];
    u32 len;

    if ((s->flags & 1) != 0) {
        len = s->len;
    } else {
        len = (u8)((struct ShortByte *)s)->len;
    }
    func_00107100(s, 0, len, tail, guard, flag[0]);
}

}
