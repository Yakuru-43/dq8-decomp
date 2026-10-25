// range: 0x105E30 0x105F44
// Best factory draft (attempt 3). CLASS structural score=57; see func_00105E30.md.
#include "common.h"

extern s32 func_00133558(void *stream);
extern void func_00130FD0(u16 *out, char *buf, s32 len);
extern s32 func_00135DF8(s32 ch, void *stream);

typedef struct {
    u8 *cur;   /* 0x00 next byte */
    s32 left;  /* 0x04 bytes buffered */
} SubStream;

typedef struct {
    void *vt0;          /* 0x00 */
    s32 f04;            /* 0x04 */
    s32 f08;            /* 0x08 */
    s32 f0C;            /* 0x0C */
    s32 f10;            /* 0x10 */
    s32 f14;            /* 0x14 */
    s32 f18;            /* 0x18 */
    SubStream *stream;  /* 0x1C */
} Reader;

/* Peek len (< 13) bytes from the stream behind reader, decode them with
 * func_00130FD0 and return the u16 result; with push_back the bytes are
 * returned to the stream in reverse order first.  -1 on a failed read. */
s32 func_00105E30(Reader *reader, s32 len, s32 push_back) {
    u16 val;
    char buf[12];
    s32 i;
    char *p;
    s32 ch;
    SubStream *st;
    s32 rem;
    u8 *cur;

    if ((u32)len >= 0xD) {
        return -1;
    }
    i = 0;
    p = buf;
    while (i < len) {
        st = reader->stream;
        rem = st->left - 1;
        st->left = rem;
        if (rem < 0) {
            ch = func_00133558(reader->stream);
        } else {
            st = reader->stream;
            cur = st->cur;
            st->cur = cur + 1;
            ch = *cur;
        }
        if (ch == -1) {
            return -1;
        }
        *p = (char)ch;
        p = p + 1;
        i = i + 1;
    }
    func_00130FD0(&val, buf, len);
    if (push_back != 0) {
        while (len > 0) {
            len = len - 1;
            if (func_00135DF8(buf[len], reader->stream) == -1) {
                return -1;
            }
        }
    }
    return val;
}
