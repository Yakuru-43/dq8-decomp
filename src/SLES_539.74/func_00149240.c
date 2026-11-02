// range: 0x149240 0x149380
#include "common.h"

typedef union Vec {
    u128 q;
    struct { f32 x, y, z, w; } v;
} Vec;

typedef struct Obj {
    u8 pad0[0x1C];
    Vec *vec;
    u8 pad20[0x9];
    u8 b29;
    u8 pad2A;
    u8 b2B;
    u8 b2C;
    u8 pad2D[0x23];
    Vec buf;
    Vec quads[4];
} Obj;

static inline void CopyQuads(Obj *dst, Obj *src) {
    dst->quads[0] = src->quads[0];
    dst->quads[1] = src->quads[1];
    dst->quads[2] = src->quads[2];
    dst->quads[3] = src->quads[3];
    dst->b29 = 1;
}

void func_00149240(Obj *src, Obj *dst) {
    Vec *sv;
    Vec *dv;

    if (src->vec != 0) {
        CopyQuads(dst, src);
        dv = dst->vec;
        sv = src->vec;
        if (dv == 0) {
            if (1.0f != sv->v.x || 1.0f != sv->v.y || 1.0f != sv->v.z) {
                dst->vec = &dst->buf;
                dst->b2B = 1;
                dst->b29 = 1;
                dst->b2C = 0;
                dst->vec->q = sv->q;
                dst->b29 = 1;
            }
        } else if (dv->v.x != sv->v.x || dv->v.y != sv->v.y || dv->v.z != sv->v.z) {
            *dv = *sv;
            dst->b29 = 1;
        }
    } else {
        CopyQuads(dst, src);
    }
}
