// range: 0x364310 0x3643C0
#include "common.h"

typedef struct Buf {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ char *base;
    /* 0x18 */ s32 write;
} Buf;

u32 func_001341D8(char *);
char *func_001340C0(char *, char *);
void func_00364290(Buf *);

char *func_00364310(Buf *buf, char *str) {
    s32 pos;
    s32 len;
    char *dst;

    if (str == 0) {
        return 0;
    }
    len = func_001341D8(str) + 1;
    pos = buf->write;
    if (pos + len < 0xA000) {
        dst = buf->base + pos;
        func_001340C0(dst, str);
        buf->write = buf->write + len;
        buf->base[buf->write] = 0;
        buf->write = buf->write + 1;
        return dst;
    }
    func_00364290(buf);
    return 0;
}
