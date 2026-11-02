// best attempt 2026-11-02 factory-2: CLASS structural score=31 (30 words differ,
// 412 vs 416 bytes). Almost all of those 30 are the +/-1 word shift caused by the
// missing addiu, plus %gp_rel relocations try_match cannot resolve. The only REAL
// diff left is the address block of case 4 (see the .md note).
// range: 0x00239D70 0x00239F10
#include "common.h"

struct Tagged {
    s32 type;
    union {
        s32 i;
        f32 f;
    } v;
};

extern void *D_003E0B20;
extern void *D_003E0B24;

s32 func_00239D70(struct Tagged *o, s32 mode) {
    f32 vec[4];
    struct Tagged *t1, *t2;
    f32 fx, fy, fz;
    s32 col;
    s32 row;
    void *node;
    char *base, *tp;

    switch (mode) {
    case 3:
        fx = o[0].type == 0 ? (f32)o[0].v.i : o[0].v.f;
        vec[0] = fx;
        t1 = &o[1];
        if (o[1].type == 0) {
            fy = (f32)t1->v.i;
        } else {
            fy = t1->v.f;
        }
        vec[1] = fy;
        fz = o[2].type == 0 ? (f32)o[2].v.i : o[2].v.f;
        vec[2] = fz;
        vec[3] = 1.0f;
        node = *(void **)((char *)D_003E0B20 + 0x1930);
        if (node != 0) {
            *(u128 *)((char *)node + 0xF0) = *(u128 *)vec;
        }
        break;
    case 4:
        if (o[0].type == 1) {
            col = (s32)o[0].v.f;
        } else {
            col = o[0].v.i;
        }
        t1 = &o[1];
        if (o[1].type == 0) {
            fx = (f32)o[1].v.i;
        } else {
            fx = o[1].v.f;
        }
        vec[0] = fx;
        t2 = &o[2];
        if (o[2].type == 0) {
            fy = (f32)t2->v.i;
        } else {
            fy = t2->v.f;
        }
        vec[1] = fy;
        fz = t1[2].type == 0 ? (f32)t1[2].v.i : t1[2].v.f;
        vec[2] = fz;
        vec[3] = 1.0f;
        base = (char *)D_003E0B20;
        row = *(s32 *)((char *)D_003E0B24 + 0xA8);
        if (col >= 0) {
            if (row >= 0) {
                if (row < 0xC0) {
                    if (col < 8) {
                        tp = row * 0x20 + base + 0x130;
                        node = *(void **)(tp + col * 4);
                        if (node != 0) {
                            *(u128 *)((char *)node + 0xF0) = *(u128 *)vec;
                        }
                    }
                }
            }
        } else {
            node = *(void **)(base + 0x1930);
            if (node != 0) {
                *(u128 *)((char *)node + 0xF0) = *(u128 *)vec;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
