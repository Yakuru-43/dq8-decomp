// range: 0x105F50 0x106080
// Best factory draft (inline form, score 66; helper form scored 51 — see .md).
#include "common.h"

extern void func_00130FD0(char *dst, u16 *seed, s32 n);
extern s32 func_00138828(s32 ch);

typedef struct {
    u8 *cur;    /* 0x00 next byte */
    s32 pad04;
    s32 left;   /* 0x08 bytes buffered */
    s32 pad0C[3];
    s32 limit;  /* 0x18 */
} Stream;

typedef struct {
    u32 pad[7];
    Stream *stream; /* 0x1C */
} Reader;

s32 func_00105F50(Reader *reader, s32 count, u16 seed) {
    char buf[16];
    u16 val;
    s32 i;
    char *p;
    s32 rc;
    u8 *old;
    s32 left;

    val = seed;
    func_00130FD0(buf, &val, count);
    if (0 < count) {
        i = 0;
        p = buf;
        do {
            left = reader->stream->left - 1;
            reader->stream->left = left;
            if (left < 0) {
                if (reader->stream->left < reader->stream->limit) {
                    rc = func_00138828(*p);
                } else {
                    *reader->stream->cur = *p;
                    if ((s32)*reader->stream->cur == 10) {
                        rc = func_00138828(10);
                    } else {
                        old = reader->stream->cur;
                        reader->stream->cur = old + 1;
                        rc = *old;
                    }
                }
            } else {
                *reader->stream->cur = *p;
                old = reader->stream->cur;
                reader->stream->cur = old + 1;
                rc = *old;
            }
            if (rc == -1) {
                return -1;
            }
            i = i + 1;
            p = p + 1;
        } while (i < count);
    }
    return val;
}
