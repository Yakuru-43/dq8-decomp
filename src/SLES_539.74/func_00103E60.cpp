// range: 0x103E60 0x104040
// flags: -O4,p
// Stream gather, wide twin of func_00103AB0 over 4-byte entries: pulls what
// fits from [gptr, egptr) with an unrolled Entry::operator= copy, then takes
// the rest one by one through the underflow virtual (slot 0x28), stopping at
// the -1 (0xFFFF) eof value. Returns the number of entries taken.
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

struct Reader {
    virtual s32 v_0x08(void);
    virtual s32 v_0x0C(void);
    virtual s32 v_0x10(void);
    virtual s32 v_0x14(void);
    virtual s32 v_0x18(void);
    virtual s32 v_0x1C(void);
    virtual s32 v_0x20(void);
    virtual s32 v_0x24(void);
    virtual s32 v_0x28(void);
    u32 gptr() const { return field_08; }
    u32 egptr() const { return field_0C; }
    u16 take() {
        u32 g = field_08;
        field_08 = g + 4;
        return *(u16 *)g;
    }
    u32 field_04;
    u32 field_08;
    u32 field_0C;
};

static inline const s64 &min_s64(const s64 &a, const s64 &b) {
    return a < b ? a : b;
}

s64 func_00103E60(Reader *sb, Entry *dst, s64 n) {
    s64 avail = (s32)(sb->field_0C - sb->field_08) / 4;
    s64 total = min_s64(avail, n);
    s32 ch;

    if (total > 0) {
        Entry *out = dst;
        const Entry *cur = (const Entry *)sb->field_08;
        u32 i;

        for (i = 0; i < (u32)total; i++) {
            *out++ = *cur++;
        }
        dst += (s32)total;
        sb->field_08 += (s32)total * 4;
        n -= total;
    }
    while (n > 0) {
        if (sb->gptr() < sb->egptr()) {
            ch = sb->take();
        } else {
            ch = sb->v_0x28();
        }
        if (ch == -1) {
            break;
        }
        dst->value = (u16)ch;
        total++;
        dst++;
        n--;
    }
    return total;
}

}
