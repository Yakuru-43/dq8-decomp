// range: 0x1080E0 0x108394
#include "common.h"

extern "C" {

extern u32 func_00100970(u32);
extern void func_001007A0(u32);
extern void func_00100780(u32);
extern u32 func_00100860(u32);
extern void func_00101020(void *);
extern void func_00102670(u32, u32, u32);
extern void func_001340C0(u32, u32);
extern u32 func_001341D8(u32);
extern void func_00130FD0(u32, u32, u32);
extern void func_001075F0(void);

extern char D_003DD880[];
extern char D_003BF140[];
extern char D_003DD860[];
extern char D_003BF050[];

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

struct ShortByte {
    /* 0x00 */ u8 tag : 1;
    /* 0x01 */ u8 len : 7;
};

struct Tag {
    /* 0x00 */ u32 tag : 1;
    /* 0x04 */ u32 rest;
};

struct Cap {
    /* 0x00 */ u64 tag : 1;
    /* 0x00 */ u64 cap : 63;
};

void func_001080E0(struct Str *s, u32 n) {
    u32 word0;
    u32 len;
    u32 oldcap;
    u32 copy;
    u32 newcap;
    u32 src;
    u32 newbuf;
    u32 keep;
    u32 heap;
    char *name;
    u32 guard0;
    u32 guard1;
    u32 p4;
    u32 buf0[8];
    u32 buf1[8];

    if (n >= 0x7FFFFFFF) {
        name = D_003DD880;
        p4 = func_001341D8((u32)D_003BF140);
        guard0 = func_00100860(p4 + 1);
        guard1 = 0;
        try {
            if (guard0 != 0) {
                p4 = func_00100970(4);
                if (p4 != 0) {
                    *(u32 *)p4 = 1;
                }
                guard1 = p4;
            }
        } catch (...) {
            func_00100780(guard0);
            func_00102670(0, 0, 0);
            func_00101020(buf0);
        }
        func_001340C0(guard0, (u32)D_003BF140);
        name = D_003DD860;
        func_00102670((u32)D_003BF050, (u32)&name, (u32)func_001075F0);
    }
    word0 = s->flags;
    heap = (word0 & 1) != 0;
    if (heap != 0) {
        len = s->len;
        oldcap = word0 >> 1;
    } else {
        len = (u8)((struct ShortByte *)s)->len;
        oldcap = 0xB;
    }
    copy = n;
    if (copy >= len) {
        copy = len;
    }
    if (copy + 1 < 0xC) {
        newcap = 0xB;
    } else {
        newcap = (copy + 0x10) & ~0xF;
    }
    if (newcap == oldcap) {
        return;
    }
    if (newcap == 0xB) {
        src = s->ptr;
        newbuf = (u32)((char *)s + 1);
        keep = 0;
    } else {
        if (oldcap < newcap) {
            newbuf = func_00100970(newcap);
        } else {
            try {
                newbuf = func_00100970(newcap);
            } catch (...) {
                func_00101020(buf1);
            }
        }
        keep = 1;
        if (heap != 0) {
            src = s->ptr;
        } else {
            src = (u32)((char *)s + 1);
        }
    }
    func_00130FD0(newbuf, src, len);
    *(u8 *)(newbuf + len) = 0;
    if (heap != 0) {
        func_001007A0(src);
    }
    ((struct Tag *)s)->tag = keep;
    if (keep == 0) {
        ((struct ShortByte *)s)->len = len;
    } else {
        s->ptr = newbuf;
        s->len = len;
        ((struct Cap *)s)->cap = newcap;
    }
}

}
