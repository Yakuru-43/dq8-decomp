// range: 0x13D600 0x13D630
#include "common.h"

typedef struct {
    /* 00 */ f32 x;
    /* 04 */ f32 y;
    /* 08 */ f32 z;
} Pos;

extern s32 func_0013D410(f32 px, f32 py, f32 x0, f32 y0, f32 x1, f32 y1,
                         f32 x2, f32 y2);

/* Is point p inside the XZ triangle v0..v2?  0 outside, 1 inside,
 * 2/3/4 on the edge opposite vertex 0/1/2. */
s32 func_0013D600(Pos *p, Pos *v0, Pos *v1, Pos *v2) {
    return func_0013D410(p->x, p->z, v0->x, v0->z, v1->x, v1->z, v2->x,
                         v2->z);
}
