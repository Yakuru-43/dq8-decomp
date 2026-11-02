// range: 0x14AA80 0x14AB20
// Position setter: points the position at the inline vector on first use,
// otherwise skips the copy when the new value is the same.
#include "common.h"

extern "C" {

union Vec4 {
    s128 q;
    struct {
        f32 x, y, z, w;
    } f;
};

static inline bool Same(Vec4 *a, Vec4 *b) {
    if (a->f.x != b->f.x) {
        return false;
    }
    if (a->f.y != b->f.y) {
        return false;
    }
    if (a->f.z != b->f.z) {
        return false;
    }
    return true;
}

struct Node {
    void InitPos() {
        pos = &posBuf;
        f2B = 1;
        dirty = 1;
        f2C = 0;
    }

    char unk0[0x14];         /* 0x00 */
    Vec4 *pos;               /* 0x14 */
    char unk18[0x29 - 0x18]; /* 0x18 */
    s8 dirty;                /* 0x29 */
    s8 f2A;                  /* 0x2A */
    s8 f2B;                  /* 0x2B */
    s8 f2C;                  /* 0x2C */
    char unk2D[0x30 - 0x2D]; /* 0x2D */
    Vec4 posBuf;             /* 0x30 */
};

void func_0014AA80(Node *n, Vec4 *v) {
    Vec4 *p = n->pos;

    if (p == 0) {
        n->InitPos();
        n->pos->q = v->q;
        n->dirty = 1;
        return;
    }
    if (p->f.x != v->f.x || p->f.y != v->f.y || p->f.z != v->f.z) {
        p->q = v->q;
        n->dirty = 1;
    }
}

}
