// range: 0x23B5B0 0x23B710
#include "common.h"

extern void *D_003E0B24;

struct Tagged {
    s32 type;
    union {
        s32 i;
        f32 f;
    } v;
};

struct Args23B5B0 {
    /* 0x00 */ struct Tagged start;
    /* 0x08 */ struct Tagged x;
    /* 0x10 */ struct Tagged y;
    /* 0x18 */ struct Tagged z;
    /* 0x20 */ struct Tagged w;
    /* 0x28 */ struct Tagged rot;
    /* 0x30 */ struct Tagged count;
};

struct List23B5B0 {
    u8 pad[0x28];
    /* 0x28 */ void *entries;
    /* 0x2C */ s32 count;
};

struct Entry23B5B0 {
    u8 pad[0xD0];
    /* 0xD0 */ s128 vec;
    /* 0xE0 */ f32 rot;
};

union Vec4 {
    s128 q;
    struct {
        f32 x, y, z, w;
    } v;
};

s32 func_0023B5B0(struct Args23B5B0 *arg0, s32 arg1) {
    union Vec4 vec;
    struct List23B5B0 *list;
    struct Entry23B5B0 *entry;
    s128 quad;
    f32 rot;
    s32 i;
    s32 count;
    s32 total;
    f32 fx, fy, fz, fw;
    struct Tagged *t;

    if (arg0->start.type == 1) {
        i = (s32)arg0->start.v.f;
    } else {
        i = arg0->start.v.i;
    }

    t = &arg0->x;
    if (arg0->x.type == 0) {
        fx = (f32)t->v.i;
    } else {
        fx = t->v.f;
    }
    vec.v.x = fx;
    t = &arg0->y;
    if (arg0->y.type == 0) {
        fy = (f32)t->v.i;
    } else {
        fy = t->v.f;
    }
    vec.v.y = fy;
    t = &arg0->z;
    if (arg0->z.type == 0) {
        fz = (f32)t->v.i;
    } else {
        fz = t->v.f;
    }
    vec.v.z = fz;
    t = &arg0->w;
    if (arg0->w.type == 0) {
        fw = (f32)t->v.i;
    } else {
        fw = t->v.f;
    }
    vec.v.w = fw;
    t = &arg0->rot;
    if (arg0->rot.type == 0) {
        rot = (f32)t->v.i;
    } else {
        rot = t->v.f;
    }

    if (arg1 >= 7) {
        if (arg0->count.type == 1) {
            count = (s32)arg0->count.v.f;
        } else {
            count = arg0->count.v.i;
        }
    }

    quad = vec.q;
    total = i + count;
    while (i < total) {
        list = (struct List23B5B0 *)D_003E0B24;
        if (list != 0) {
            if (i < list->count) {
                entry = (struct Entry23B5B0 *)((char *)list->entries + i * 0x110);
            } else {
                entry = 0;
            }
        } else {
            entry = 0;
        }
        if (entry == 0) {
            return 0;
        }
        entry->vec = quad;
        i++;
        entry->rot = rot;
    }
    return 1;
}
