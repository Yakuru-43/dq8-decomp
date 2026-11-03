// best draft for func_001716B0 (try_match: CLASS structural score=342, 1156 vs 932 B)
#include "common.h"

extern s32 func_00130F38(void *, void *, s32);
extern void func_00131188(void *, s32, s32);
extern void DebugPrintf(char *, s32);

extern u8 D_003C2958;
extern u8 D_003C2960;
extern u8 D_003C2970;
extern u8 D_003C2990;

typedef struct {
    u32 pad0;
    u16 field4;
    u16 count;
    u32 base;
} Ctl;

typedef struct {
    u16 id;
    u8 tag;
    u8 pad3;
    s8 data[2];
} Rec;

s32 func_001716B0(Ctl *ctl, u8 *hdr, s32 arg2, u32 arg3, u32 arg4) {
    u16 v8;
    u16 vA;
    u16 vC;
    u32 size;
    u32 total;
    u8 *d;
    u8 *p;
    s32 i;
    Rec *rec;
    u8 *start;
    u32 totalRecs;
    s32 flag;
    s32 lastTag;
    u32 value;
    u8 b;
    s32 tag;
    s32 c;
    u8 extra;
    u8 *q;
    s32 len;

    if (func_00130F38(hdr, &D_003C2958, 4) != 0) {
        return 0;
    }
    d = (u8 *)&size + 3;
    p = hdr + 4;
    for (i = 0; i < 4; i++) {
        *d-- = *p++;
    }
    d = (u8 *)&v8 + 1;
    p = hdr + 8;
    for (i = 0; i < 2; i++) {
        *d-- = *p++;
    }
    d = (u8 *)&vA + 1;
    p = hdr + 0xA;
    for (i = 0; i < 2; i++) {
        *d-- = *p++;
    }
    d = (u8 *)&vC + 1;
    p = hdr + 0xC;
    for (i = 0; i < 2; i++) {
        *d-- = *p++;
    }
    if (func_00130F38(hdr + size + 8, &D_003C2960, 4) != 0) {
        return 0;
    }
    d = (u8 *)&total + 3;
    p = hdr + size + 0xC;
    for (i = 0; i < 4; i++) {
        *d-- = *p++;
    }
    ctl->base = arg3;
    start = hdr + size + 0x10;
    rec = (Rec *)ctl->base;
    if (rec == 0) {
        return 0;
    }
    totalRecs = arg4 / 6 - (arg4 / 6 % 6) * 6 / 6;
    ctl->count = 0;
    flag = 0;
    lastTag = -1;
    for (;;) {
        if (totalRecs == ctl->count) {
            flag = 1;
            break;
        }
        func_00131188(rec, 0, 6);
        value = 0;
        for (;;) {
            b = *p;
            value += b & 0x7F;
            p++;
            if (!(b & 0x80)) {
                break;
            }
            value <<= 7;
        }
        tag = *p++;
        if (!(tag & 0x80)) {
            tag = lastTag;
            p--;
        }
        if (tag == 0xFF) {
            c = *(s8 *)p;
            if (c == 0x2F) {
                break;
            }
            extra = p[1];
            q = p + 2;
            p = q + extra;
        } else {
            len = 0;
            if ((tag & 0xF0) == 0xD0 || (tag & 0xF0) == 0xC0) {
                len = 1;
            } else if ((tag & 0xF0) == 0xE0 || (tag & 0xF0) == 0xB0 ||
                       (tag & 0xF0) == 0x80 || (tag & 0xF0) == 0x90) {
                len = 2;
            }
            if (len < 0) {
                DebugPrintf((char *)&D_003C2970, tag);
            } else {
                rec->id = value;
                rec->tag = tag;
                for (i = 0; i < len; i++) {
                    rec->data[i] = *(s8 *)p;
                    p++;
                }
                ctl->count = ctl->count + 1;
                rec = (Rec *)((u8 *)rec + 6);
            }
        }
        lastTag = tag;
        if (total < p - start) {
            continue;
        }
        break;
    }
    if (flag != 0) {
        DebugPrintf((char *)&D_003C2990, 0);
        ctl->count = 0;
        ctl->base = 0;
        return 0;
    }
    rec->tag = 0;
    ctl->count = ((u8 *)rec + 6 - (u8 *)ctl->base) / 6 -
                 (((u8 *)rec + 6 - (u8 *)ctl->base) / 6 % 6) * 6 / 6;
    ctl->field4 = ((vC * 15 * 15) / 60 - ((vC * 15 * 15) / 60 % 60) * 60 / 60);
    return ctl->count * 3 * 2;
}
