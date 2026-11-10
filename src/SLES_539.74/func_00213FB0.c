// range: 0x213FB0 0x214200
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    s32 ix;
    s32 iy;
    s8 kind;
} Marker;

typedef struct {
    u8 pad0[0x24];
    s16 *tex;
    u8 pad28[0x418 - 0x28];
    s32 attr0;
    s32 attr1;
    u8 pad420[0x488 - 0x420];
    f32 zoom;
} MapState;

s32 func_0015F490(void);
void func_001419A0(s32, s32, f32);
f32 func_00129E60(f32);
s32 func_00141BF0(s32);
void func_0013E320(s32, s32);
void func_0013E410(s32, s32);
void func_0013E420(s32, s32);
void func_0013E200(s32, s32);
void func_0022B020(s32, s16 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00141B00(s32);
extern MapState *D_003E0908;
extern Marker *D_003E08E4;
extern s16 D_003E08E8;
extern const s16 D_003C7B90[];

void func_00213FB0(s32 mode) {
    s32 handle;
    s32 obj;
    s32 scale;
    Marker *m;
    s32 i;
    s32 x;
    s32 y;
    s32 row;
    s16 *tex;

    handle = func_0015F490();
    tex = D_003E0908->tex;
    if (tex == NULL) {
        return;
    }
    func_001419A0(handle, *tex, 1.0f);
    scale = func_00129E60(D_003E0908->zoom) * 32.0f + 160.0f;
    obj = func_00141BF0(handle);
    func_0013E320(obj, 1);
    func_0013E410(obj, 1);
    func_0013E420(obj, 1);
    func_0013E200(obj, 2);
    m = D_003E08E4;
    if (mode == 0) {
        for (i = 0; i < D_003E08E8; i++, m++) {
            row = (m->kind - 1) * 2;
            func_0022B020(obj, D_003E0908->tex, (s32)(m->x - 4.0f), (s32)(m->y - 4.0f), 8, 8,
                          D_003C7B90[row], D_003C7B90[row + 1],
                          16, 16, scale, D_003E0908->attr0);
        }
    }
    if (mode == 1) {
        for (i = 0; i < D_003E08E8; i++, m++) {
            row = (m->kind - 1) * 2;
            x = m->ix - 8;
            y = m->iy - 8;
            if (x >= -0x100 && y >= -0x100 && x < 0x100 && y < 0x100) {
                func_0022B020(obj, D_003E0908->tex, x, y, 16, 16,
                              D_003C7B90[row], D_003C7B90[row + 1],
                              16, 16, scale, D_003E0908->attr1);
            }
        }
    }
    func_0013E200(obj, 0);
    func_00141B00(handle);
}
