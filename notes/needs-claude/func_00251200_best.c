// best C for func_00251200 (NOT matching — needs-claude)
// variant A (pointer local, best score 27):
#include "common.h"

s32 WaitSema(s32);
s32 SignalSema(s32);

typedef struct Buf {
    /* 0x00 */ s32 unk00[3];
    /* 0x0C */ s32 sema;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ u8 f18;
    /* 0x19 */ u8 f19;
    /* 0x1A */ u8 f1A;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
} Buf;

void func_00251200(Buf *buf) {
    volatile s32 *sema;

    buf->f10 = 0;
    buf->f14 = 0;
    sema = &buf->sema; // thread-shared
    buf->f18 = 1;
    buf->f1A = 0;
    buf->f19 = 0;
    buf->f20 = 0;
    buf->f1C = 0;
    if (buf->sema > 0) {
        WaitSema(*sema);
    }
    buf->f24 = 0;
    if (*sema > 0) {
        SignalSema(*sema);
    }
}
