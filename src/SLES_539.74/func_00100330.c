// range: 0x100330 0x100440
#include "common.h"

extern s32 func_0011BBA8(s32, s32);
extern s32 func_0011BFB0(s32, void *, s32);
extern s32 func_0011C1F0(s32, char *, s32);
extern void func_0011BE38(s32);
extern void func_00100320(char *);
extern void FlushCache(s32);
extern void func_00131188(char *, s32, s32);
extern void func_00100DE0(s32, s32, s32, s32);

s32 func_00100330(s32 a0, char *image) {
    s32 result;
    s32 size;
    s32 handle;

    result = 0;
    size = 0;
    handle = func_0011BBA8(a0, 1);
    if (handle >= 0) {
        size = func_0011BFB0(handle, 0, 2);
        func_0011BFB0(handle, 0, 0);
    }
    if (size > 0) {
        size = func_0011C1F0(handle, image, size);
    }
    if (handle >= 0) {
        func_0011BE38(handle);
    }
    if (size > 0) {
        func_00100320(image);
        handle = *(s32 *)(image + 0x14);
        FlushCache(0);
        FlushCache(2);
        if (handle != 0) {
            func_00131188(image + size, 0, handle);
        }
        func_00100DE0(*(s32 *)(image + 0x18), *(s32 *)(image + 0x1C), 0, 0);
        result = 1;
    }
    return result;
}
