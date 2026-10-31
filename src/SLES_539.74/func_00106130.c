// range: 0x106130 0x106250
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

/* Read count (< 13) bytes from the stream into a stack buffer, parse them
 * with func_00130FD0 (which writes its result into `last`) and return it;
 * with flag the bytes are returned to the stream in reverse order.  -1 on
 * a failed read or push-back. */
s32 func_00106130(Reader *reader, s32 count, s32 flag) {
    u8 last;
    char buf[15];
    s32 i;
    char *p;
    s32 ch;

    if ((u32)count >= 13) {
        return -1;
    }
    i = 0;
    if (i < count) {
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
        } while (++i < count);
    }
    func_00130FD0(&last, buf, count);
    if (flag != 0) {
        if (count > 0) {
            do {
                count--;
                if (func_00135DF8(buf[count], reader->stream) == -1) {
                    return -1;
                }
            } while (count > 0);
        }
    }
    return last;
}
