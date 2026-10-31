// range: 0x22B020 0x22B120
#include "common.h"

void func_0013F6C0(void *, s32);                              /* extern */
void func_0013EB30(void *, s32);                              /* extern */
void func_0013ECD0(void *, s32, s32, s32, s32);               /* extern */
void func_0013EBF0(void *, s32, s32);                         /* extern */
void func_0013EF90(void *, s32, s32, s32);                    /* extern */
void func_0013F450(void *);                                   /* extern */

void func_0022B020(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9,
                   s32 arg10, s32 arg11) {
    func_0013F6C0(arg0, 6);
    func_0013EB30(arg0, arg1);
    func_0013ECD0(arg0, arg10, arg10, arg10, arg11);
    func_0013EBF0(arg0, arg6, arg7);
    func_0013EF90(arg0, arg2, arg3, 0);
    func_0013EBF0(arg0, arg6 + arg8 - 1, arg7 + arg9 - 1);
    func_0013EF90(arg0, arg2 + arg4, arg3 + arg5, 0);
    func_0013F450(arg0);
}
