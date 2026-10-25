// range: 0x106F80 0x106FF0
// Truncates the string at `pos` through the shared erase helper: below the end
// it drops everything from pos on, at-or-above the end it passes the
// overflow distance instead.
#include "common.h"

extern "C" {

extern void func_001077C0(void *, u32, u32, u32, u32);

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

struct ShortByte {
    /* 0x00 */ u8 tag : 1;
    /* 0x01 */ u8 len : 7;
};

inline u32 Str_Len(struct Str *s) {
    if ((s->flags & 1) != 0) {
        return s->len;
    }
    return (u8)((struct ShortByte *)s)->len;
}

void func_00106F80(struct Str *s, u32 pos, u32 extra) {
    u32 len;

    len = Str_Len(s);
    if (len < pos) {
        func_001077C0(s, len, 0, pos - len, extra);
    } else {
        func_001077C0(s, pos, len - pos, 0, 0);
    }
}

}
