// range: 0x107F20 0x108090
// Splice worker: decodes the source string, bounds-checks the caller's
// count, then hands the tail slice to the shared splice worker.
// NOT MATCHED — best attempt, score 88, see func_00107F20.md
#include "common.h"

extern "C" {

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

struct ShortByte {
    /* 0x00 */ u8 tag : 1;
    /* 0x01 */ u8 len : 7;
};

extern u32 func_001341D8(char *);
extern u32 func_00100860(u32);
extern void func_00102C10(struct Str *, u32);
extern void func_001340C0(u32, char *);
extern void func_00102670(char *, u32 *, void (*)());
extern u32 func_00107100(void *, u32, u32, void *, u32, s8);
extern void func_00107690(void);

extern char D_003BEFD0[];
extern char D_003BEFF0[];
extern u32 D_003DD880[];
extern u32 D_003DD870[];

u32 func_00107F20(struct Str *out, u32 pos, u32 arg2, struct Str *src,
                  u32 count, u32 limit) {
    u8 flag[4];
    u32 vtbl;
    struct Str strAC;
    u32 size;
    char *data;
    u32 left;
    u32 *sel;
    u32 take;

    if ((src->flags & 1) == 0) {
        data = (char *)src + 1;
        size = ((struct ShortByte *)src)->len;
    } else {
        data = (char *)src->ptr;
        size = src->len;
    }
    if (size < count) {
        u32 msgLen;
        u32 buf;

        vtbl = (u32)D_003DD880;
        msgLen = func_001341D8(D_003BEFD0);
        buf = func_00100860(msgLen + 1);
        func_00102C10(&strAC, buf);
        func_001340C0(strAC.flags, D_003BEFD0);
        vtbl = (u32)D_003DD870;
        func_00102670(D_003BEFF0, &vtbl, func_00107690);
    }
    left = size - count;
    data += count;
    sel = (left < limit) ? &left : &limit;
    take = *sel;
    return func_00107100(out, pos, arg2, data, (u32)(data + take), flag[0]);
}

}
