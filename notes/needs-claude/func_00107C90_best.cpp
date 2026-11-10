// range: 0x107C90 0x107D30
// Splice-from-front wrapper: the worker gets the distance from the string's
// data to the caller's end position, the char buffer, and a guard pointer.
#include "common.h"

extern "C" {

extern void func_00107100(void *, u32, u32, void *, void *, s8);

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

inline u32 Str_Data(struct Str *s) {
    if ((s->flags & 1) != 0) {
        return s->ptr;
    }
    return (u32)s + 1;
}

void func_00107C90(s32 *out, struct Str *s, s64 end, u8 c) {
    u8 buf[16];
    u32 off;

    buf[3] = c;
    off = (u32)((s32)end - (s32)Str_Data(s));
    func_00107100(s, off, 0, &buf[3], &buf[4], buf[12]);
    *out = Str_Data(s) + off;
}

}
