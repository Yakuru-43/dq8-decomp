// best attempt for func_00103AB0 (see func_00103AB0.md). NOT for src/.
// range: 0x103AB0 0x103BE0
#include "common.h"

extern "C" {

extern void *func_00130FD0(void *dst, const void *src, u32 n);

struct StreamBuf {
    virtual s32 v_0x08(void);
    virtual s32 v_0x0C(void);
    virtual s32 v_0x10(void);
    virtual s32 v_0x14(void);
    virtual s32 v_0x18(void);
    virtual s32 v_0x1C(void);
    virtual s32 v_0x20(void);
    virtual s32 v_0x24(void);
    virtual s32 underflow(void);
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 *field_08;
    /* 0x0C */ u8 *field_0C;
    u8 *gptr() const { return field_08; }
    u8 *egptr() const { return field_0C; }
};

static inline const s64 &min_s64(const s64 &a, const s64 &b) {
    return a < b ? a : b;
}

s64 func_00103AB0(StreamBuf *sb, char *s, s64 n) {
    s64 avail = (s64)(sb->egptr() - sb->gptr());
    s64 count = min_s64(avail, n);
    if (count > 0) {
        func_00130FD0(s, sb->gptr(), (u32)count);
        s += (s32)count;
        sb->field_08 += (s32)count;
        n -= count;
    }
    if (n > 0) {
        do {
            s32 ch;
            if (sb->gptr() < sb->egptr()) {
                ch = *sb->field_08++;
            } else {
                ch = sb->underflow();
            }
            if (ch == -1) {
                break;
            }
            *s++ = (char)ch;
            count++;
        } while (--n > 0);
    }
    return count;
}

}
