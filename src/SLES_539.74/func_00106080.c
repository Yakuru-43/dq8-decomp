// range: 0x106080 0x106130
#include "common.h"

typedef struct {
    u8 *cur;  /* 0x00 next byte */
    s32 left; /* 0x04 bytes buffered */
} SubStream;

extern s32 func_00133558(SubStream *stream);
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

/* Read one byte from the stream behind reader, refilling through
 * func_00133558 when the buffer is empty; with flag the byte is also
 * handed back to the stream through func_00135DF8.  -1 on a failed read
 * or push-back. */
s32 func_00106080(Reader *reader, s32 flag) {
    s32 ch;
    s32 rc;

    if ((reader->stream->left -= 1) < 0) {
        ch = func_00133558(reader->stream);
    } else {
        ch = *reader->stream->cur++;
    }
    if (ch == -1) {
        return -1;
    }
    if (flag != 0) {
        rc = func_00135DF8(ch, reader->stream);
        if (rc == -1) {
            return -1;
        }
    }
    return ch;
}
