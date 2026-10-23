// range: 0x213FB0 0x214200
// best attempt, try 3/20, cut off by session end (see func_00213FB0.md)
#include "common.h"

s32 func_0015F490(void);                               /* extern */
void func_001419A0(s32, s32, f32);                     /* extern */
f32 func_00129E60(s32, f32);                           /* extern */
s32 func_00141BF0(s32);                                /* extern */
void func_0013E320(s32, s32);                           /* extern */
void func_0013E410(s32, s32);                           /* extern */
void func_0013E420(s32, s32);                           /* extern */
void func_0013E200(s32, s32);                           /* extern */
void func_0022B020(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
void func_00141B00(s32);                                /* extern */
extern char *D_003E0908;
extern char *D_003E08E4;
extern s16 D_003E08E8;
extern s16 D_003C7B90[];

void func_00213FB0(s32 arg0) {
    s32 handle;
    s32 obj;
    s32 scale;
    char *entry;
    s32 i;
    s32 x;
    s32 y;
    s32 row;

    handle = func_0015F490();
    if (M2C_FIELD(D_003E0908, char *, 0x24) == 0) {
        return;
    }
    func_001419A0(handle, *(s16 *)M2C_FIELD(D_003E0908, char *, 0x24), 1.0f);
    scale = (s32)(func_00129E60(handle, M2C_FIELD(D_003E0908, f32 *, 0x488)) * 32.0f + 160.0f);
    obj = func_00141BF0(handle);
    func_0013E320(obj, 1);
    func_0013E410(obj, 1);
    func_0013E420(obj, 1);
    func_0013E200(obj, 2);
    entry = D_003E08E4;
    if (arg0 == 0) {
        for (i = 0; i < D_003E08E8; i++) {
            x = (s32)(M2C_FIELD(entry, f32 *, 0) - 4.0f);
            y = (s32)(M2C_FIELD(entry, f32 *, 4) - 4.0f);
            row = (s32)M2C_FIELD(entry, s8 *, 0x10) - 1;
            func_0022B020(obj, M2C_FIELD(D_003E0908, s32 *, 0x24), x, y, 8, 8,
                          D_003C7B90[row * 2], D_003C7B90[row * 2 + 1],
                          16, 16, scale, M2C_FIELD(D_003E0908, s32 *, 0x418));
            entry += 0x14;
        }
    }
    if (arg0 == 1) {
        for (i = 0; i < D_003E08E8; i++) {
            x = M2C_FIELD(entry, s32 *, 8) - 8;
            y = M2C_FIELD(entry, s32 *, 0xC) - 8;
            row = (s32)M2C_FIELD(entry, s8 *, 0x10) - 1;
            if ((-0x100 <= x) && (-0x100 <= y) && (x < 0x100) && (y < 0x100)) {
                func_0022B020(obj, M2C_FIELD(D_003E0908, s32 *, 0x24), x, y,
                              16, 16, D_003C7B90[row * 2], D_003C7B90[row * 2 + 1],
                              16, 16, scale,
                              M2C_FIELD(D_003E0908, s32 *, 0x41C));
            }
            entry += 0x14;
        }
    }
    func_0013E200(obj, 0);
    func_00141B00(handle);
}
