// range: 0x144380 0x144620
#include "common.h"

extern u32 func_00109F98(s32);
extern void FlushCache(s32);
extern void func_00109220(s32);
extern void func_001089C8(void *);
extern s32 sceGsPutDrawEnv(void *);
extern void func_0010A568(u32, s32, s32);

void func_00144380(void *arg0) {
    s32 env;
    u32 handle;
    s32 buf[12];
    char *b;
    s32 *dst;
    s32 *src;
    s32 n;
    u16 h;
    u16 h2;
    s32 w;
    s32 w2;
    u64 r;

    handle = func_00109F98(2);
    env = *(s32 *)((char *)arg0 + 0x270);
    b = (char *)buf;
    dst = buf;
    src = (s32 *)(env + 0x44);
    for (n = 5; n > 0; n--) {
        *dst++ = *src++;
        *dst++ = *src++;
    }
    h = *(u16 *)(b + 0x18);
    *(u16 *)(b + 0x18) = (h & 0xF000) | (((h & 0xFFF) + *(u16 *)((char *)arg0 + 0xF08)) & 0xFFF);
    w = *(s32 *)(b + 0x18);
    *(s32 *)(b + 0x18) =
        (w & 0xFF800FFF) |
        (s32)(((((u64)w >> 12) + *(s32 *)((char *)arg0 + 0xF0C)) & 0x7FF) << 12);
    FlushCache(0);
    func_00109220(0);
    func_001089C8(buf);
    sceGsPutDrawEnv((void *)(env + 0x70));
    func_0010A568(handle, 0, 0);
    if (*(s32 *)(env + 0x1C) == 0) {
        *(u64 *)0x12000000 = 0xFF22; /* hw-register */
    } else {
        *(u64 *)0x12000000 = 0x7F23; /* hw-register */
        r = (u64)(*(u16 *)(b + 0x10) & 0x1FF);
        r |= (u64)*(u8 *)(b + 0x11) >> 1 << 9;
        r |= (u64)*(s32 *)(b + 0x10) >> 15 << 15;
        r |= (u64)0x800 << 32;
        *(u64 *)0x12000070 = r; /* hw-register */
        h = *(u16 *)(b + 0x28);
        h2 = *(u16 *)(b + 0x18);
        *(u16 *)(b + 0x28) = (h & 0xF000) | (h2 & 0xFFF);
        w = *(s32 *)(b + 0x28);
        w2 = *(s32 *)(b + 0x18);
        *(s32 *)(b + 0x28) = (w & 0xFF800FFF) | ((s32)(((u64)w2 >> 12) & 0x7FF) << 12);
        h = *(u16 *)(b + 0x2C);
        h2 = *(u16 *)(b + 0x1C);
        *(u16 *)(b + 0x2C) = (h & 0xF000) | (h2 & 0xFFF);
        h = *(u16 *)(b + 0x2A);
        h2 = *(u16 *)(b + 0x1A);
        *(u16 *)(b + 0x2A) = (h & ~0x780) | ((((u64)h2 >> 7) & 0xF) << 7);
        w = *(s32 *)(b + 0x2C);
        w2 = *(s32 *)(b + 0x1C);
        *(s32 *)(b + 0x2C) = (w & 0xFF800FFF) | ((s32)((((u64)w2 >> 12) - 1) & 0x7FF) << 12);
        h = *(u16 *)(b + 0x2E);
        h2 = *(u16 *)(b + 0x1E);
        *(u8 *)(b + 0x2B) =
            (u8)(*(u8 *)(b + 0x2B) & ~0x18) | (u8)((((u64)*(u8 *)(b + 0x1B) >> 3) & 3) << 3);
        *(u16 *)(b + 0x2E) = (h & ~0xFF80) | ((((u64)h2 >> 7) & 0x1FF) << 7);
        *(u8 *)(b + 0x2B) =
            (u8)(*(u8 *)(b + 0x2B) & ~0xE0) | (u8)((((u64)*(u8 *)(b + 0x1B) >> 5) & 7) << 5);
        *(u64 *)0x12000080 = *(u64 *)(b + 0x28); /* hw-register */
    }
}
