// range: 0x2D8E80 0x2D8F20
#include "common.h"

s32 func_0015F490();
void func_002D8F40(s128 *);
void func_002D8F30(s128 *, char *);
void func_002D8F20(s128 *, char *);
void func_00154ED0(s128 *, f32);
void func_00166AE0(s128 *);
f32 func_001FF5E0(s128 *);
void func_00143160(s32, f32);
void func_00143030(s32, s128 *);
void func_001430F0(s32);

s32 func_002D8E80(s32 arg0, s32 arg1, char *arg2) {
    char buf[0xD0];
    s32 temp_v0;
    char *temp_s0;
    s32 temp_s1;

    temp_v0 = func_0015F490();
    temp_s0 = *(char **)(arg2 + 0x2C);
    temp_s1 = temp_v0;
    func_002D8F40((s128 *)buf);
    func_002D8F30((s128 *)buf, temp_s0 + 0x10);
    func_002D8F20((s128 *)buf, temp_s0 + 0x20);
    func_00154ED0((s128 *)buf, *(f32 *)temp_s0);
    func_00166AE0((s128 *)buf);
    func_00143160(temp_s1, func_001FF5E0((s128 *)buf));
    func_00143030(temp_s1, (s128 *)buf);
    func_001430F0(temp_s1);
    return 0;
}
