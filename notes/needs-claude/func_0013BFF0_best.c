// best C for func_0013BFF0 (needs-claude: VU0 chunks not C-expressible)
#include "common.h"

extern f32 func_0012A008(void);
extern f32 func_00129E60(f32);
extern f32 D_003DF410;   /* 0.97f */

typedef struct {
    f32 x, y, z, w;
} Vec4;

static f32 vec_dot(Vec4 *a, Vec4 *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

void func_0013BFF0(Vec4 *out, Vec4 *inA, Vec4 *inB, f32 t) {
    Vec4 a = *inA;
    Vec4 b = *inB;
    f32 dot = vec_dot(&a, &b);
    f32 oneMinus;
    f32 r;

    if (dot < 0.0f) {
        dot = -dot;
        b.x = -b.x;
        b.y = -b.y;
        b.z = -b.z;
        b.w = -b.w;
    }
    oneMinus = 1.0f - t;
    if (dot <= D_003DF410) {
        a.x = a.x * oneMinus + b.x * t;
        a.y = a.y * oneMinus + b.y * t;
        a.z = a.z * oneMinus + b.z * t;
        a.w = a.w * oneMinus + b.w * t;
        dot = vec_dot(&a, &a);
        dot = 1.0f / dot;
        out->x = a.x * dot;
        out->y = a.y * dot;
        out->z = a.z * dot;
        out->w = a.w * dot;
        return;
    }
    r = func_0012A008();
    {
        f32 b1 = func_00129E60(r);
        f32 c1 = func_00129E60(oneMinus * r);
        f32 d1 = func_00129E60(t * r);
        b1 = 1.0f / b1;
        oneMinus = c1 * b1;
        r = d1 * b1;
    }
    out->x = a.x * oneMinus + b.x * r;
    out->y = a.y * oneMinus + b.y * r;
    out->z = a.z * oneMinus + b.z * r;
    out->w = a.w * oneMinus + b.w * r;
}
