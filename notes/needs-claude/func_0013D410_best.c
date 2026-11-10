// range: 0x13D410 0x13D600
#include "common.h"

/* Point-in-triangle test: is (px, py) inside the triangle
 * (x0, y0), (x1, y1), (x2, y2)?  0 = outside, 1 = inside,
 * 2/3/4 = on the edge opposite vertex 0/1/2. */
s32 func_0013D410(f32 px, f32 py, f32 x0, f32 y0, f32 x1, f32 y1, f32 x2,
                  f32 y2) {
    f32 t;
    f32 c0;
    f32 c1;
    f32 c2;

    t = (x0 < x1) ? ((x0 < x2) ? x0 : x2) : ((x1 < x2) ? x1 : x2);
    if (!(t <= px)) {
        return 0;
    }
    t = (x0 > x1) ? ((x0 <= x2) ? x2 : x0) : ((x1 <= x2) ? x2 : x1);
    if (!(px <= t)) {
        return 0;
    }
    t = (y0 < y1) ? ((y0 < y2) ? y0 : y2) : ((y1 < y2) ? y1 : y2);
    if (!(t <= py)) {
        return 0;
    }
    t = (y0 > y1) ? ((y0 <= y2) ? y2 : y0) : ((y1 <= y2) ? y2 : y1);
    if (!(py <= t)) {
        return 0;
    }

    c0 = (x1 - x0) * (py - y0) - (y1 - y0) * (px - x0);
    c1 = (x2 - x1) * (py - y1) - (y2 - y1) * (px - x1);
    c2 = (x0 - x2) * (py - y2) - (y0 - y2) * (px - x2);

    if (c0 == 0.0f) {
        return 2;
    }
    if (c1 == 0.0f) {
        return 3;
    }
    if (c2 == 0.0f) {
        return 4;
    }
    if (!(c0 <= 0.0f) && !(c1 <= 0.0f) && !(c2 <= 0.0f)) {
        return 1;
    }
    if (c0 < 0.0f && c1 < 0.0f && c2 < 0.0f) {
        return 1;
    }
    return 0;
}
