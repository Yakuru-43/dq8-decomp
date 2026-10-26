// range: 0x2116B0 0x211770
#include "common.h"

extern f32 func_00129E60(f32 x);
extern f32 func_00129BC0(f32 x);

extern f32 D_003E0934;

typedef struct {
    u8 pad[0x2C];
    f32 originX;
    f32 originY;
    f32 scaleX;
    f32 scaleY;
} View;

/* Projects a world position to screen space, rotated by D_003E0934. */
void func_002116B0(View *view, f32 *pos, f32 *out) {
    f32 sy;
    f32 sx;
    f32 s;

    if (view == 0) {
        return;
    }
    sx = view->scaleX * (pos[0] - view->originX);
    sy = view->scaleY * (pos[2] - view->originY);
    s = func_00129E60(D_003E0934);
    out[0] = 256.0f + (sx * func_00129BC0(D_003E0934) - sx * s);
    s = func_00129E60(D_003E0934);
    out[1] = 224.0f + (sy * func_00129BC0(D_003E0934) + sy * s);
}
