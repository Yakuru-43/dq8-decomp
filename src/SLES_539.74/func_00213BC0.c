// range: 0x213BC0 0x213C80
#include "common.h"

s32 func_0015F490(void);                                    /* extern */
void func_001419A0(s32, s32, f32);                          /* extern */
void func_0022ACB0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_00141BF0(s32);                                     /* extern */
void func_002112C0(s32);                                    /* extern */
void func_00141B00(s32);                                    /* extern */
extern char *D_003E0908;

s32 func_00213BC0(s32 arg0, s32 arg1) {
    s32 handle;

    if (M2C_FIELD(D_003E0908, s32 *, 0) == 0) {
        return -1;
    }
    handle = func_0015F490();
    func_001419A0(handle, *(s16 *)M2C_FIELD(D_003E0908, s32 *, 0), 1.0f);
    func_0022ACB0(M2C_FIELD(D_003E0908, s32 *, 0), 0, 0, 0x200, 0x1C0, 0, 0,
                  0x200, 0x1C0, arg1);
    func_002112C0(func_00141BF0(handle));
    func_00141B00(handle);
    return arg0;
}
