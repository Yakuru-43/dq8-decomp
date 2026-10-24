// range: 0x30A320 0x30A4B0
#include "common.h"

s32 func_0024C670(s32);                                /* extern */
void func_0013F6C0(void *, s32);                        /* extern */
void func_0013EB30(char *, s32);                        /* extern */
void func_0013ECD0(char *, s32, s32, s32, s32);         /* extern */
void func_0013EBF0(char *, s32, s32);                   /* extern */
void func_0013EF90(char *, s32, s32, s32);              /* extern */
s32 func_0013F450(char *);                              /* extern */
void func_001339E0(char *, char *, s32);                /* extern */
s32 func_0015F450(void);                                /* extern */
s32 func_0015AEF0(s32, char *, s32);                    /* extern */
extern char D_003D0238[];

s32 func_0030A320(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    char buf90[0x20];
    s32 count;
    s32 page;
    s32 tile_x;
    s32 tile_y;
    s32 handle;
    s32 mgr;

    tile_x = 0;
    tile_y = 0;
    count = func_0024C670(arg1);
    if (count >= 0) {
        page = count % 64;
        tile_x = (page % 8) << 5;
        tile_y = (page / 8) << 5;
        func_001339E0(buf90, D_003D0238, count / 64 + 1);
        mgr = func_0015F450();
        handle = func_0015AEF0(mgr, buf90, -1);
    } else {
        handle = 0;
    }
    func_0013F6C0(arg0, 6);
    func_0013EB30(arg0, handle);
    func_0013ECD0(arg0, arg4, arg4, arg4, arg5);
    func_0013EBF0(arg0, tile_x, tile_y);
    func_0013EF90(arg0, arg2, arg3, 0);
    func_0013EBF0(arg0, tile_x + 0x20, tile_y + 0x20);
    func_0013EF90(arg0, arg2 + 0x26, arg3 + 0x2C, 0);
    return func_0013F450(arg0);
}
