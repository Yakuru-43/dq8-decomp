// range: 0x140580 0x140830
// best attempt (factory-1, 2026-10-26): CLASS structural score=148 (144 words differ,
// 668 vs 684 bytes) — all three loops and the push shape diverge from the schedule.
#include "common.h"

extern "C" {

typedef union Rec {
    u128 q;
    u32 w[4];
} Rec;

extern Rec D_003A0C40;

void func_0013FD20(void *, u32 *, s32);   /* extern */

struct Entry {
    /* 0x0C */ u32 count;
    /* 0x10 */ u32 *tags;
    /* 0x14 */ s32 argc;
    /* 0x18 */ u32 *argv;
    /* 0x1C */ u32 tag1;
    /* 0x20 */ u32 tag2;
};

struct Block {
    /* 0x00 */ u8 pad_0[0x28];
    /* 0x28 */ u8 *base;
    /* 0x2C */ u32 used;
};

struct Obj {
    /* 0x00 */ u32 field_00;
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 pad_08[0x3BAC - 0x08];
    /* 3BAC */ s32 count;
    /* 3BB0 */ Entry ***entries;
    /* 3BB8 */ s32 *counts;
    u8 *cursor() const { return field_04; }
    void bump() { field_04 += 0x10; }
    void push(u32 tag) {
        *(u128 *)cursor() = D_003A0C40.q;
        *(u32 *)(cursor() + 4) = tag & 0x0FFFFFFF;
        bump();
    }
};

s32 func_00140580(Obj *obj, s32 idx) {
    Entry **p;
    Entry *entry;
    Entry *prev;
    u32 *tags;
    u32 *pt;
    u32 n;
    u32 c;
    u32 i;
    u32 t;
    u32 lastTag;
    Block *blk;
    u32 *hdr;

    if (idx >= 0) {
        if (idx < obj->count) {
            if (obj->entries[idx] != 0) {
                u32 x = *(u32 *)((char *)obj + (obj->field_00 << 2) + 8);
                blk = x != 0 ? (Block *)(x + 8) : 0;
                hdr = (u32 *)(blk->base + (blk->used << 4));
                hdr[0] = 0x60000000;
                hdr[1] = 0;
                hdr[2] = 0x14000064;
                hdr[3] = 0;
                lastTag = 0;
                n = obj->counts[idx];
                p = obj->entries[idx] + (n - 1);
                prev = 0;
                for (i = 0; i < n; i++) {
                    entry = *p;
                    p--;
                    c = entry->count;
                    tags = entry->tags;
                    if (prev == 0 || c != prev->count) {
                        for (t = 0; t < c; t++) {
                            obj->push(tags[t]);
                        }
                    } else {
                        pt = prev->tags;
                        if (pt != tags) {
                            for (t = 0; t < c; t++) {
                                if (tags[t] != pt[t]) {
                                    obj->push(tags[t]);
                                }
                            }
                        }
                    }
                    func_0013FD20(obj, entry->argv, entry->argc);
                    if (lastTag != entry->tag1) {
                        lastTag = entry->tag1;
                        obj->push(entry->tag1);
                    }
                    obj->push((u32)hdr);
                    obj->push(entry->tag2);
                    prev = entry;
                }
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

}
