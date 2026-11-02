// range: 0x103980 0x103AB0
// flags: -O4,p
#include "common.h"

extern "C" {

extern void func_00130FD0(void *dest, const void *src, s32 n);

struct Writer {
    virtual s32 v_0x08(s32);
    virtual s32 v_0x0C(s32);
    virtual s32 v_0x10(s32);
    virtual s32 v_0x14(s32);
    virtual s32 v_0x18(s32);
    virtual s32 v_0x1C(s32);
    virtual s32 v_0x20(s32);
    virtual s32 v_0x24(s32);
    virtual s32 v_0x28(s32);
    virtual s32 v_0x2C(s32);
    virtual s32 v_0x30(s32);
    virtual s32 v_0x34(u8);
    u8 *cursor() const { return field_14; }
    u8 *end() const { return field_18; }
    /* 0x04 */ s32 data[4];
    /* 0x14 */ u8 *field_14;
    /* 0x18 */ u8 *field_18;
};

static inline bool is_eof(s32 c) {
    return c == -1;
}

s64 func_00103980(Writer *o, char *src, s64 n) {
    s64 space = (s64)(o->end() - o->cursor());
    s64 *pick;
    s64 written;
    s32 ch;
    s32 result;
    u8 *slot;

    if (space < n) {
        pick = &space;
    } else {
        pick = &n;
    }
    written = *pick;
    if (written > 0) {
        func_00130FD0(o->cursor(), src, (s32)written);
        src += (s32)written;
        o->field_14 = o->cursor() + (s32)written;
        n -= written;
    }
    if (n > 0) {
        do {
            ch = *src++;
            if (o->cursor() < o->end()) {
                slot = o->field_14++;
                *(s8 *)slot = (s8)ch;
                result = *slot;
            } else {
                result = o->v_0x34((u8)ch);
            }
            if (is_eof(result)) {
                break;
            }
            written++;
            n--;
        } while (n > 0);
    }
    return written;
}

}
