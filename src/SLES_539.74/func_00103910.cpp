// range: 0x103910 0x103960
// streambuf-style uflow: ask the virtual underflow (vtable +0x24) for more
// input; on EOF return -1, else return the byte at the get pointer and step it.
#include "common.h"

extern "C" {

struct Scanner {
    virtual s32 v_0x08();
    virtual s32 v_0x0C();
    virtual s32 v_0x10();
    virtual s32 v_0x14();
    virtual s32 v_0x18();
    virtual s32 v_0x1C();
    virtual s32 v_0x20();
    virtual s32 v_0x24();
    u8 *gbump_post() { return gptr++; }
    /* 0x04 */ u8 *eback;
    /* 0x08 */ u8 *gptr;
};

static inline bool is_eof(s32 c) {
    return c == -1;
}

s32 func_00103910(Scanner *scanner) {
    s32 c;

    if (is_eof(scanner->v_0x24())) {
        c = -1;
    } else {
        c = *scanner->gbump_post();
    }
    return c;
}

}
