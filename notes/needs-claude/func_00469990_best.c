// range: 0x469990 0x469C00
// flags: -flag divbyzerocheck
#include "common.h"

extern char D_0047E760[] __attribute__((section(".data")));

extern void *func_15F450(void);
extern void *func_15AEF0(void *, char *, s32);
extern void func_0046AA70(void *, void *, u32 *, u32 *);

s32 func_00469990(s32 arg0, s32 arg1, s32 arg2) {
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    void *p5;
    void *p6;
    u8 *src;
    u32 base2;
    s32 f4;
    s32 f2;
    s32 i;
    s32 j;
    s32 q;
    s32 r;
    s32 m;
    s32 n;
    u32 arg50[4];
    u32 arg60[4];
    u8 c;

    p1 = func_15F450();
    p2 = func_15AEF0(p1, D_0047E760, -1);
    p3 = func_15AEF0(p2, D_0047E760, -1);
    f4 = *(s16 *)((char *)p3 + 4);
    f2 = *(s16 *)((char *)p3 + 2);
    base2 = *(u32 *)((char *)p3 + 0x50);
    src = (u8 *)(*(u32 *)((char *)p2 + 0x50) + ((arg2 << 4) + 0x27B95));
    for (i = (arg0 << 4) + 1; i < ((arg0 + 1) << 4) + 1; i++) {
        j = 489;
        do {
            *(u8 *)(base2 + j + f2 * (f4 - i)) = *src;
            j = j + 1;
        } while (j < 512);
    }
    r = arg0 % 4;
    q = arg0 / 4;
    for (m = q * 48 + 1; m < (q + 1) * 48 + 1; m++) {
        for (n = r * 48 + 297; n < (r + 1) * 48 + 296; n++) {
            *(u8 *)(base2 + n + f2 * (f4 - m)) = *src;
        }
    }
    p4 = func_15F450();
    p5 = func_15AEF0(p4, D_0047E760, -1);
    p6 = func_15AEF0(p5, D_0047E760, -1);
    arg60[0] = q * 48 + 4;
    arg60[1] = r * 48 + 299;
    arg60[2] = 42;
    arg60[3] = 42;
    arg50[1] = (arg1 % 6) * 48 + 257;
    arg50[0] = (arg1 / 6) * 48 + 257;
    arg50[2] = 42;
    arg50[3] = 42;
    c = *(u8 *)(*(u32 *)((char *)p5 + 0x50) + 0x1FF);
    func_0046AA70(p6, p5, arg60, arg50);
    return 1;
}
