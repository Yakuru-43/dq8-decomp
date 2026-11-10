// range: 0x46A270 0x46A3F0
#include "common.h"

struct Cell {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
};

s32 func_15F450(s32);                                              /* extern */
s32 func_15AEF0(s32, void *, s32);                                 /* extern */
s32 func_0046AA70(s32, s32, struct Cell *, struct Cell *, s32);    /* extern */
extern M2C_UNK D_0047E760 __attribute__((section(".data")));
extern u32 D_003E17B0 __attribute__((section(".sdata")));

s32 func_0046A270(s32 arg0) {
    s32 obj;
    s32 ent;
    s32 r3;
    s32 r4;
    s32 var_s2;
    s32 var_s3;
    struct Cell q;
    struct Cell s;

    obj = func_15F450(arg0);
    func_15AEF0(obj, &D_0047E760, -1);
    func_15AEF0(obj, &D_0047E760, -1);
    if (arg0 >= 5) {
        var_s3 = 1;
        var_s2 = arg0 - 5;
    } else {
        var_s3 = 0;
        var_s2 = arg0;
    }
    ent = func_15F450(obj);
    obj = *(s32 *)(D_003E17B0 + arg0 * 0x40 + 0x20);
    r3 = func_15AEF0(ent, &D_0047E760, -1);
    r4 = func_15AEF0(ent, &D_0047E760, -1);
    s.x0 = var_s2 * 0x30 + 0xC;
    s.y0 = var_s3 * 0x30 + 0xC;
    s.x1 = 0x2A;
    s.y1 = 0x2A;
    q.y0 = (obj % 6) * 42 + 257;
    q.x0 = (obj / 6) * 42 + 257;
    q.x1 = 0x2A;
    q.y1 = 0x2A;
    func_0046AA70(r4, r3, &s, &q, *(u8 *)(*(u32 *)(r3 + 0x50) + 0x1FF));
    return 1;
}
