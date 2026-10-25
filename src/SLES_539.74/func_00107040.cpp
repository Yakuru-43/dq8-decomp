// range: 0x107040 0x107090
// Replace-from-front through the shared splice helper: position 0, the
// string's own length, and the caller's count as the trailing argument.
#include "common.h"

extern "C" {

extern void func_00107090(void *, u32, u32, u32);

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

void func_00107040(struct Str *s, u32 count) {
    func_00107090(s, 0, Str_Len(s), count);
}

}
