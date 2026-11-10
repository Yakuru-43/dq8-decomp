// range: 0x460830 0x460BA0
// best attempt, NOT matched (register allocation / spill order off, see .md)
#include "common.h"

typedef struct {
    char pad0[0x20];
    s32 y0;      /* 0x20 */
    s32 x0;      /* 0x24 */
    s32 y1;      /* 0x28 */
    s32 x1;      /* 0x2C */
    s32 cx;      /* 0x30 */
    s32 cy;      /* 0x34 */
    f32 scaleX;  /* 0x38 */
    f32 scaleY;  /* 0x3C */
    f32 rect[4]; /* 0x40 */
    s32 enabled; /* 0x50 */
} Board;

typedef struct {
    u16 unk0;
    s16 x;
} Glyph;

extern char *func_15F490(void);
M2C_UNK func_145450();
M2C_UNK func_145440();
M2C_UNK func_15F450();
M2C_UNK func_15AEF0();
M2C_UNK func_13E200();
M2C_UNK func_13E320();
M2C_UNK func_13E300();
M2C_UNK func_13E360();
M2C_UNK func_13F6C0();
M2C_UNK func_13EC60();
M2C_UNK func_13EB30();
M2C_UNK func_13EBF0();
M2C_UNK func_13EE00();
M2C_UNK func_13F450();

void func_00460830(Board *obj, void *win) {
    char *handle;
    f32 wScale;
    f32 hScale;
    Glyph *tex;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 halfW;
    s32 halfH;
    s32 left;
    s32 right;
    s32 top;
    s32 bottom;
    f32 d;

    if (obj->enabled == 0) {
        return;
    }
    handle = func_15F490();
    wScale = (f32)func_145450(handle);
    hScale = (f32)func_145440(handle);
    tex = (Glyph *)func_15AEF0(func_15F450(), obj, -1);
    if (tex == 0) {
        return;
    }
    x0 = obj->x0;
    x1 = obj->x1;
    halfW = (s32)(obj->scaleX * (f32)((x1 - x0) * 16)) / 2;
    y0 = obj->y0;
    y1 = obj->y1;
    halfH = (s32)(obj->scaleY * (f32)((y1 - y0) * 16)) / 2;
    left = obj->cx * 16 - halfW;
    right = obj->cx * 16 + halfW;
    top = obj->cy * 16 - halfH;
    bottom = obj->cy * 16 + halfH;
    if ((f32)left > 16.0f * wScale) {
        return;
    }
    if ((f32)top > 16.0f * hScale) {
        return;
    }
    if (right < 0) {
        return;
    }
    if (bottom < 0) {
        return;
    }
    if (left < 0) {
        x0 = x0 - left / 16;
        left = 0;
    }
    if (top < 0) {
        y0 = y0 - top / 16;
        top = 0;
    }
    if ((f32)right > 16.0f * wScale) {
        d = ((f32)right - 16.0f * wScale) / 16.0f;
        right = (s32)(16.0f * wScale);
        x1 = (s32)((f32)x1 - d);
    }
    if ((f32)bottom > 16.0f * hScale) {
        d = ((f32)bottom - 16.0f * hScale) / 16.0f;
        bottom = (s32)(16.0f * hScale);
        y1 = (s32)((f32)y1 - d);
    }
    func_13E200(win, 0);
    func_13E320(win, 1);
    func_13E300(win, 1);
    func_13E360(win, 1);
    func_13F6C0(win, 6);
    func_13EC60(win, obj->rect);
    func_13EB30(win, tex);
    func_13EBF0(win, x0, (s32)tex->x - y0);
    func_13EE00(win, left, top, 0);
    func_13EBF0(win, x1, (s32)tex->x - y1);
    func_13EE00(win, right, bottom, 0);
    func_13F450(win);
}
