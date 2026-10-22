// range: 0x2FF6E0 0x2FF890
#include "common.h"

s32 func_0015F490(void);
void *func_00141BF0(s32);         /* extern */
void func_00141B00(s32);          /* extern */
s32 func_00145450(s32);           /* extern */
s32 func_00145440(s32);           /* extern */
void func_0013F6C0(void *, s32);  /* extern */
void func_0013EBB0(void *, s64, s64);
void func_0013F450(void *);       /* extern */
void func_002FF300(void *, void *, void *, s32, s32, s32);

struct Float4 { f32 x; f32 y; f32 z; f32 w; };

void func_002FF6E0(M2C_UNK arg0, struct Float4 *def, M2C_UNK arg2, M2C_UNK arg3,
                   s32 color, s32 arg5, s32 arg6, s32 arg7) {
    struct Float4 d;
    s32 handle;
    void *obj;
    s32 w;
    s32 h;
    s32 handle2;

    d = *def;
    handle = func_0015F490();
    if (handle == 0) {
        return;
    }
    obj = func_00141BF0(handle);
    if (obj == 0) {
        return;
    }
    if (obj != 0) {
        w = func_00145450(func_0015F490());
        func_0013F6C0(obj, 6);
        func_0013EBB0(obj, 0x40, ((u64)(s32)(w - 1) << 16) | ((u64)(s32)arg6 << 32) |
                      ((u64)(s32)arg7 << 48));
        func_0013F450(obj);
    }
    func_002FF300((void *)arg0, obj, &d, color, arg5, 0);
    if (obj != 0) {
        handle2 = func_0015F490();
        w = func_00145450(handle2);
        h = func_00145440(handle2);
        func_0013F6C0(obj, 6);
        func_0013EBB0(obj, 0x40,
                      ((u64)(s32)(w - 1) << 16) | ((u64)(s32)(h - 1) << 48));
        func_0013F450(obj);
    }
    func_00141B00(handle);
}
