// range: 0x2374D0 0x237860
// CLASS structural score=211 (204 words differ, 940 vs 912 bytes), -O3.
// Padded write to a streambuf: (n1+n3) bytes of payload (src1, src2) plus
// fill bytes up to the formatter's pending width (field_30), positioned by
// flags & 0xB0: 0x10 centers (fill before the payload), 0x20 right-aligns
// (fill after). Each byte goes through an inline sputc on the put area; the
// streambuf is dropped when a write comes back -1. The width is cleared and
// the streambuf written out through out.
#include "common.h"

extern "C" {

struct StreamBuf {
    virtual s32 v_0x08(void);
    virtual s32 v_0x0C(void);
    virtual s32 v_0x10(void);
    virtual s32 v_0x14(void);
    virtual s32 v_0x18(void);
    virtual s32 v_0x1C(void);
    virtual s32 v_0x20(void);
    virtual s32 v_0x24(void);
    virtual s32 v_0x28(void);
    virtual s32 v_0x2C(void);
    virtual s32 v_0x30(void);
    virtual s32 overflow(u8 c);
    /* 0x04 */ u8 pad_04[0x10];
    /* 0x14 */ u8 *pptr_;
    /* 0x18 */ u8 *epptr_;
};

static inline void sputc(StreamBuf **psb, s32 c) {
    StreamBuf *sb = *psb;
    s32 ch;
    if (sb->pptr_ < sb->epptr_) {
        u8 *p = sb->pptr_++;
        *p = (char)c;
        ch = (s32)*p;
    } else {
        ch = sb->overflow((u8)c);
    }
    if (ch == -1) {
        *psb = 0;
    }
}

struct Formatter {
    /* 0x04 */ u8 pad_04[0x2C];
    /* 0x30 */ s64 field_30;
    /* 0x38 */ u16 flags;
};

void func_002374D0(StreamBuf **out, StreamBuf *sb, Formatter *f, s32 fill,
                   s8 *src1, s32 n1, s8 *src2, s32 n3) {
    s32 pad = 0;
    if ((n1 + n3) < f->field_30) {
        pad = (s32)(f->field_30 - (n1 + n3));
    }
    u16 mode = f->flags & 0xB0;
    s32 i;

    if (mode != 0x20 && mode != 0x10) {
        if (0 < pad) {
            for (i = 0; i < pad; i++) {
                if (sb != 0) {
                    sputc(&sb, fill);
                }
            }
        }
    }
    if (0 < n1) {
        for (i = 0; i < n1; i++) {
            if (sb != 0) {
                sputc(&sb, *src1);
            }
            src1++;
        }
    }
    if (mode == 0x10) {
        if (0 < pad) {
            for (i = 0; i < pad; i++) {
                if (sb != 0) {
                    sputc(&sb, fill);
                }
            }
        }
    }
    if (0 < n3) {
        for (i = 0; i < n3; i++) {
            if (sb != 0) {
                sputc(&sb, *src2);
            }
            src2++;
        }
    }
    if (mode == 0x20) {
        if (0 < pad) {
            for (i = 0; i < pad; i++) {
                if (sb != 0) {
                    sputc(&sb, fill);
                }
            }
        }
    }
    *out = sb;
    f->field_30 = 0;
}

}
