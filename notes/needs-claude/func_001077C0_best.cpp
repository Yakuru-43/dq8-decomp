// range: 0x1077C0 0x107B90
// Replace: erase min(n, len - pos) chars at pos, insert `count` copies of
// `ch` there; grow the heap buffer (16-align, then double) when the result
// does not fit the current capacity.
// CLASS structural score=236 (201 words differ, 836 vs 976 bytes) — see
// notes/needs-claude/func_001077C0.md. The two extern u8 globals need the
// .data section attribute (plain `extern u8` lands in .sdata and the link
// dies on R_MIPS_GPREL16).
#include "common.h"

extern "C" {

typedef struct StrHdr {
    /* 0x0 */ u32 flags; /* bit0: on heap; on heap: capacity = flags >> 1 */
    /* 0x4 */ u32 len;
    /* 0x8 */ char *data;
} StrHdr;

extern M2C_UNK D_003DD860 __attribute__((section(".data")));
extern M2C_UNK D_003DD870 __attribute__((section(".data")));
extern M2C_UNK D_003DD880 __attribute__((section(".data")));
extern u8 D_0039CE20 __attribute__((section(".data")));
extern u8 D_0039CE28 __attribute__((section(".data")));
extern char D_003BEFD0[];
extern char D_003BEFF0[];
extern char D_003BF030[];
extern char D_003BF050[];

extern u32 func_001341D8(char *);
extern u32 func_00100860(u32, u32);
extern void func_00102C10(M2C_UNK *, u32);
extern void func_001340C0(M2C_UNK, char *);
extern void func_00102670(char *, M2C_UNK *, void (*)(void));
extern void func_001075F0(void);
extern void func_00107690(void);
extern char *func_00100970(u32);
extern void func_001007A0(char *);
extern void func_00130FD0(char *, char *, u32);
extern void func_00131080(char *, char *, u32);
extern void func_00131188(char *, s32, u32);

void func_001077C0(StrHdr *s, u32 pos, u32 n, u32 count, u8 ch) {
    u32 flags = s->flags;
    u32 inHeap = flags & 1;
    u32 len;
    u32 cap;
    char *data;
    u32 erase;
    u32 *sel;
    u32 eraseCount;
    u32 newlen;
    u32 tail;
    char *buf;
    u32 newcap;
    u32 name;
    u32 base;

    if (inHeap != 0) {
        data = s->data;
        len = s->len;
        cap = (u32)flags >> 1;
    } else {
        len = *(u8 *)s >> 1;
        cap = 11;
        data = (char *)s + 1;
    }

    if (pos > len) {
        M2C_UNK msg;
        M2C_UNK arg;

        M2C_FIELD(&msg, M2C_UNK **, 0) = &D_003DD880;
        name = func_001341D8(D_003BEFD0);
        base = func_00100860(name + 1, name);
        func_00102C10(&arg, base);
        func_001340C0(arg, D_003BEFD0);
        M2C_FIELD(&msg, M2C_UNK **, 0) = &D_003DD870;
        func_00102670(D_003BEFF0, &msg, func_00107690);
    }

    erase = len - pos;
    sel = &n;
    if (erase < n) {
        sel = &erase;
    }
    eraseCount = *sel;

    if (!(count < 0x7FFFFFFF) || 0x7FFFFFFE - count < len - eraseCount) {
        M2C_UNK msg;
        M2C_UNK arg;

        M2C_FIELD(&msg, M2C_UNK **, 0) = &D_003DD880;
        name = func_001341D8(D_003BF030);
        base = func_00100860(name + 1, name);
        func_00102C10(&arg, base);
        func_001340C0(arg, D_003BF030);
        M2C_FIELD(&msg, M2C_UNK **, 0) = &D_003DD860;
        func_00102670(D_003BF050, &msg, func_001075F0);
    }

    tail = len - (pos + eraseCount);
    newlen = count + (len - eraseCount);

    if (newlen >= cap) {
        newcap = (cap + 15) & ~15;
        while (newcap < newlen + 1) {
            newcap = (newcap * 2 + 15) & ~15;
        }
        buf = func_00100970(newcap);
        if (pos != 0) {
            func_00130FD0(buf, data, pos);
        }
        func_00131188(buf + pos, ch, count);
        if (tail != 0) {
            func_00130FD0(buf + pos + count, data + pos + eraseCount, tail);
        }
        buf[newlen] = D_0039CE20;
        if (inHeap != 0) {
            func_001007A0(data);
        } else {
            s->flags = (s->flags & ~2) | 1;
        }
        s->data = buf;
        s->len = newlen;
        s->flags = (s->flags & 1) | (newcap << 1);
    } else {
        if (tail != 0) {
            func_00131080(data + pos + count, data + pos + eraseCount, tail);
        }
        func_00131188(data + pos, ch, count);
        data[newlen] = D_0039CE28;
        if (inHeap == 0) {
            u8 b0 = *(u8 *)s;
            *(u8 *)s = (u8)((b0 & ~0xFF) | ((newlen & 0x7F) << 1));
        }
        s->len = newlen;
    }
}

}
