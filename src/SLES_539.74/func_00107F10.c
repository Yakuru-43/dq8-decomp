// range: 0x107F10 0x107F20
// Raw accessor: the heap arm's length field, not the short form's count.
#include "common.h"

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

u32 func_00107F10(struct Str *s) {
    return s->len;
}
