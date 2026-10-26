// range: 0x105E30 0x105F50
#include "common.h"

typedef struct {
    u8 *cur;  /* 0x00 next byte */
    s32 left; /* 0x04 bytes buffered */
} SubStream;

extern s32 func_00133558(SubStream *stream);
extern void *func_00130FD0(void *dst, const void *src, u32 n);
extern s32 func_00135DF8(s32 ch, SubStream *stream);

typedef struct {
    void *vt0;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    SubStream *stream; /* 0x1C */
} Reader;

/* Read len (< 13) bytes from the stream, copy them into a value with
 * func_00130FD0 (memcpy) and return its low 16 bits; with push_back the
 * bytes are returned to the stream in reverse order.  -1 on a failed read
 * or push. */
s32 func_00105E30(Reader *reader, u32 len, s32 push_back) {
    u32 val;
    char buf[12];
    s32 i;
    char *p;
    s32 ch;

    if (len >= 13) {
        return -1;
    }
    i = 0;
    if (i < (s32)len) {
        p = buf;
        do {
            if ((reader->stream->left -= 1) < 0) {
                ch = func_00133558(reader->stream);
            } else {
                ch = *reader->stream->cur++;
            }
            if (ch == -1) {
                return -1;
            }
            *p++ = ch;
        } while (++i < (s32)len);
    }
    func_00130FD0(&val, buf, len);
    if (push_back != 0) {
        if ((s32)len > 0) {
            do {
                len--;
                if (func_00135DF8(buf[len], reader->stream) == -1) {
                    return -1;
                }
            } while ((s32)len > 0);
        }
    }
    return (u16)val;
}
