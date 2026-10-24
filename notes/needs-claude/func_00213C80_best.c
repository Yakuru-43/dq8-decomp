// range: 0x213C80 0x213FB0
// best attempt, try 3/20, cut off by session end (see func_00213C80.md)
#include "common.h"

s32 func_0015F490(void);                                          /* extern */
s32 func_0015F450(void);                                          /* extern */
char *func_0015AEF0(s32, char *, s32);                             /* extern */
void func_001419A0(s32, s32, f32);                                 /* extern */
s32 func_00141BF0(s32);                                            /* extern */
void func_002112C0(s32);                                           /* extern */
void func_0013E2F0(s32, s32);                                      /* extern */
s32 func_00133F78(char *, char *);                                 /* extern */
void func_0022B020(s32, char *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
void func_00141B00(s32);                                           /* extern */
extern char *D_003E0908;
extern char D_003C7CE8[];

s32 func_00213C80(s32 arg0, s32 arg1) {
    s32 handle;
    s32 x;
    s32 y;
    s32 pos[8];
    s32 tile[8];
    char *sprite;
    s32 obj;
    s32 rowBase;
    s32 colBase;
    s32 base;
    s32 i;
    s32 j;
    char *ptr;
    s32 k;

    handle = func_0015F490();
    x = M2C_FIELD(D_003E0908, s32 *, 0x450);
    y = M2C_FIELD(D_003E0908, s32 *, 0x454);
    pos[0] = x;
    pos[4] = x;
    pos[1] = y;
    pos[3] = y;
    pos[2] = x + 0x200;
    pos[6] = x + 0x200;
    pos[5] = y + 0x1C0;
    pos[7] = y + 0x1C0;
    sprite = func_0015AEF0(func_0015F450(), D_003C7CE8, -1);
    if (sprite != 0) {
        func_001419A0(handle, M2C_FIELD(sprite, s16 *, 0), 1.0f);
        obj = func_00141BF0(handle);
        func_002112C0(obj);
        func_0013E2F0(obj, 0);
        rowBase = (M2C_FIELD(D_003E0908, s32 *, 0x450) + 0x1B80DC) % 0x1B8 - 0x294;
        colBase = (M2C_FIELD(D_003E0908, s32 *, 0x454) + 0x1800C0) % 0x180 - 0x25C;
        for (i = 0; i < 4; i++) {
            base = rowBase + 440 * i;
            for (j = 0; j < 4; j++) {
                func_0022B020(obj, sprite, base, colBase + 384 * j,
                              0x200, 0x1C0, 0, 0, 0x200, 0x1C0, 0x80, arg1);
            }
        }
        func_00141B00(handle);
    }
    for (k = 0; k < 4; k++) {
        tile[2 * k] = 0x200;
        tile[2 * k + 1] = 0x1C0;
        ptr = (char *)M2C_FIELD(D_003E0908 + 4, s32 *, 4 * k);
        if ((ptr != 0) && (func_00133F78(ptr + 8, D_003C7CE8) == 0)) {
            tile[2 * k + 1] += 0xC0;
            pos[2 * k] -= 0x60;
            pos[2 * k + 1] -= 0x60;
            tile[2 * k] += 0xC0;
        }
    }
    for (k = 0; k < 4; k++) {
        ptr = (char *)M2C_FIELD(D_003E0908 + 4, s32 *, 4 * k);
        if (ptr != 0) {
            func_001419A0(handle, M2C_FIELD(ptr, s16 *, 0), 1.0f);
            obj = func_00141BF0(handle);
            func_002112C0(obj);
            func_0013E2F0(obj, 0);
            func_0022B020(obj, ptr, pos[2 * k], pos[2 * k + 1],
                          tile[2 * k], tile[2 * k + 1], 0, 0,
                          0x200, 0x1C0, 0x80, arg1);
            func_00141B00(handle);
        }
    }
    return arg0;
}
