// range: 0x2FFCC0 0x2FFD60
#include "common.h"

s32 func_0015F490(void);
s32 func_00145450(s32);           /* extern */
s32 func_00145440(s32);           /* extern */
void func_0013F6C0(void *, s32);  /* extern */
void func_0013EBB0(void *, s64, s64);
void func_0013F450(void *);       /* extern */

void func_002FFCC0(void *obj) {
    s32 handle;
    s32 h;
    s32 w;

    if (obj == 0) {
        return;
    }
    handle = func_0015F490();
    w = func_00145450(handle);
    h = func_00145440(handle);
    func_0013F6C0(obj, 6);
    func_0013EBB0(obj, 0x40, ((u64)(s32)(w - 1) << 16) | ((u64)(s32)(h - 1) << 48));
    func_0013F450(obj);
}
