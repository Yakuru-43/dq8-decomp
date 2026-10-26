// range: 0x13E950 0x13EB30
#include "common.h"

void func_0013F240(void *, s32, s32, s32, s32);
void func_0013F0E0(void *);

typedef union {
    u128 q;
    s32 w[4];
} QueueEnt;

typedef struct {
    /* 000 */ u8 pad[0xF4];
    /* 0F4 */ QueueEnt *cursor;
    /* 0F8 */ u8 pad2[0x24];
    /* 11C */ s32 mode;
    /* 120 */ u8 pad3[8];
    /* 128 */ s32 origin_x;
    /* 12C */ s32 origin_y;
    /* 130 */ s32 size_x;
    /* 134 */ s32 size_y;
} Queue;

void func_0013E950(Queue *o, QueueEnt *d) {
    QueueEnt *e;

    func_0013F240(o, 6, 0x441, 0, 3);

    e = o->cursor;
    o->cursor = e + 1;
    e->q = d[0].q;

    e = o->cursor;
    o->cursor = e + 2;

    if (o->mode == 1) {
        e[0].q = d[1].q;
    } else if (o->mode == 2) {
        e[0].w[0] = d[1].w[0] + o->origin_x;
        e[0].w[1] = d[1].w[1] + o->origin_y;
        e[0].w[2] = d[1].w[2];
        e[0].w[3] = d[1].w[3];
    } else {
        e[0].w[0] = d[1].w[0] + o->origin_x - o->size_x / 2;
        e[0].w[1] = d[1].w[1] + o->origin_y - o->size_y / 2;
        e[0].w[2] = d[1].w[2];
        e[0].w[3] = d[1].w[3];
    }

    if (o->mode == 1) {
        e[1].q = d[2].q;
    } else if (o->mode == 2) {
        e[1].w[0] = d[2].w[0] + o->origin_x;
        e[1].w[1] = d[2].w[1] + o->origin_y;
        e[1].w[2] = d[2].w[2];
        e[1].w[3] = d[2].w[3];
    } else {
        e[1].w[0] = d[2].w[0] + o->origin_x - o->size_x / 2;
        e[1].w[1] = d[2].w[1] + o->origin_y - o->size_y / 2;
        e[1].w[2] = d[2].w[2];
        e[1].w[3] = d[2].w[3];
    }

    func_0013F0E0(o);
}
