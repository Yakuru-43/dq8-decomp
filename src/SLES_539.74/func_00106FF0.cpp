// range: 0x106FF0 0x107040
// Erase from the string's own length on: hands the shared erase helper the
// current length plus the caller's two trailing arguments.
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

void func_00106FF0(struct Str *s, u32 pos, u32 extra) {
    func_001077C0(s, Str_Len(s), 0, pos, extra);
}

}
