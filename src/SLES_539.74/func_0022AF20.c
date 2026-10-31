// range: 0x22AF20 0x22B020
#include "common.h"

void func_0013F6C0(void *, s32);                              /* extern */
void func_0013EB30(void *, s32);                              /* extern */
void func_0013ECD0(void *, s32, s32, s32, s32);               /* extern */
void func_0013EBF0(void *, s32, s32);                         /* extern */
void func_0013EF90(void *, s32, s32, s32);                    /* extern */
void func_0013F450(void *);                                   /* extern */

void func_0022AF20(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_0013F6C0(arg0, 6);
    func_0013EB30(arg0, arg1);
    func_0013ECD0(arg0, 0x80, 0x80, 0x80, arg8);
    func_0013EBF0(arg0, arg4, arg5);
    func_0013EF90(arg0, arg2, arg3, 0);
    func_0013EBF0(arg0, arg4 + arg6 - 1, arg5 + arg7 - 1);
    func_0013EF90(arg0, arg2 + arg6, arg3 + arg7, 0);
    func_0013F450(arg0);
}
