// range: 0x105D30 0x105D80
#include "common.h"

extern char D_003DD710[];
extern char D_003DD750[];

typedef struct {
    void *vt0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    char pad24[0x40];
    s8 f64;
    s8 f65;
    s8 f66;
} S_buf;

S_buf *func_00105D30(S_buf *q, s32 arg1) {
    q->vt0 = D_003DD710;
    q->f4 = 0;
    q->f8 = 0;
    q->fC = 0;
    q->f10 = 0;
    q->f14 = 0;
    q->f18 = 0;
    q->vt0 = D_003DD750;
    q->f1C = arg1;
    q->f20 = 0;
    q->f64 = 0;
    q->f66 = 1;
    q->f65 = 0;
    return q;
}
