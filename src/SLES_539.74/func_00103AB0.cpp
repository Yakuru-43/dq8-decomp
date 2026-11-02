// range: 0x103AB0 0x103BE0
// flags: -O4,p
// streambuf-style xsgetn: copy what is left in the get area in one block, then
// read the rest byte by byte through sbumpc (virtual uflow at vtable +0x28).
// The gptr post-increment goes through an inline member (gbump_post); a plain
// `*field_08++` puts the uflow call inline instead of after the bulk copy.
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
    virtual s32 uflow(void);
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 *field_08;
    /* 0x0C */ u8 *field_0C;
    u8 *gptr() const { return field_08; }
    u8 *egptr() const { return field_0C; }
    u8 *gbump_post() { return field_08++; }
    s32 sbumpc() {
        if (gptr() < egptr()) {
            return *gbump_post();
        }
        return uflow();
    }
};

static inline bool is_eof(s32 c) {
    return c == -1;
}

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
    while (n > 0) {
        s32 ch = sb->sbumpc();
        if (is_eof(ch)) {
            break;
        }
        *s++ = (char)ch;
        count++;
        n--;
    }
    return count;
}

}
