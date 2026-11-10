// Best draft for func_00107C10 (score 17, CLASS structural) — NOT matched,
// kept out of src/. See func_00107C10.md for the wall.
// range: 0x107C10 0x107C90
#include "common.h"

extern "C" {

extern void func_00107100(void *, u32, u32, u32, u32, s8);

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

void func_00107C10(s32 *out, struct Str *s, s64 pos) {
    u32 data;
    u8 flag[4];

    data = Str_Data(s);
    func_00107100(s, (u32)((s32)pos - (s32)data), 1, 0, 0, flag[0]);
    *out = pos;
}

}
