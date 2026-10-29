// range: 0x103C10 0x103DF0
// flags: -O4,p
// Stream write of n 4-byte entries: bulk-copies what fits in [cursor, end),
// then pushes the rest one by one through the overflow virtual (slot 0x34).
// Library code built at -O4,p: CW unrolls the bulk `*dst++ = *cur++` loop 8x
// itself (sltiu 9 pre-test, remainder loop); Entry::operator= copies only the
// low halfword (lhu/sh on 4-byte entries).
#include "common.h"

extern "C" {

struct Entry {
    u16 value;
    u16 field_02;

    Entry &operator=(const Entry &o) {
        value = o.value;
        return *this;
    }
};

struct Writer {
    virtual s32 v_0x08(s32 arg);
    virtual s32 v_0x0C(s32 arg);
    virtual s32 v_0x10(s32 arg);
    virtual s32 v_0x14(s32 arg);
    virtual s32 v_0x18(s32 arg);
    virtual s32 v_0x1C(s32 arg);
    virtual s32 v_0x20(s32 arg);
    virtual s32 v_0x24(s32 arg);
    virtual s32 v_0x28(s32 arg);
    virtual s32 v_0x2C(s32 arg);
    virtual s32 v_0x30(s32 arg);
    virtual s32 v_0x34(s32 c);
    s32 field_04;
    s32 field_08;
    s32 field_0C;
    s32 field_10;
    Entry *cursor;                  /* +0x14 */
    Entry *end;                     /* +0x18 */
};

static inline const s64 &min_s64(const s64 &a, const s64 &b) {
    return a < b ? a : b;
}

s64 func_00103C10(Writer *w, Entry *src, s64 n) {
    s64 avail = w->end - w->cursor;
    s64 total = min_s64(avail, n);
    s32 c;
    s32 ch;

    if (total > 0) {
        Entry *dst = w->cursor;
        const Entry *cur = src;
        u32 i;

        for (i = 0; i < (u32)total; i++) {
            *dst++ = *cur++;
        }
        src += (s32)total;
        w->cursor += (s32)total;
        n -= total;
    }
    while (n > 0) {
        c = src->value;
        src++;
        if (w->cursor < w->end) {
            Entry *p = w->cursor++;
            p->value = (u16)c;
            ch = p->value;
        } else {
            ch = w->v_0x34(c);
        }
        if (ch == -1) {
            break;
        }
        total++;
        n--;
    }
    return total;
}

}
