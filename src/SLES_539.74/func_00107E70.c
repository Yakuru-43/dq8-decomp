// range: 0x107E70 0x107F10
// Assign: short sources copy the 12-byte header block word for word; a heap
// source zeroes the destination header, grows it, then splices the whole
// source buffer in through the shared splice worker.
#include "common.h"

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);

struct Str *func_00107E70(struct Str *dest, struct Str *src) {
    struct Str *d;
    u8 flag[4];

    d = dest;
    if ((src->flags & 1) != 0) {
        d->flags = 0;
        d->len = 0;
        d->ptr = 0;
        func_001080E0(d, src->len);
        func_00107100(d, 0, 0, src->ptr, src->ptr + src->len, flag[0]);
    } else {
        *d = *src;
    }
    return d;
}
