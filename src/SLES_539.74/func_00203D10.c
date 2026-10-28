// range: 0x203D10 0x203DF0
#include "common.h"

s32 func_00201DB0(s32);
s32 func_00206080(char *, s32);
void func_00206A50(s32, s32);
void func_00201D10(void);
void func_00204B40(char *, s32, u32, s32);
s32 func_00206A60(s32, s32, s32);
s32 func_00206C20(s32, s32, s32);
s32 func_0024C7C0(s32, s32);

s32 func_00203D10(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_s1;
    s32 temp_s0;

    if (func_00206080(arg0, arg1) == 0) {
        return -1;
    }
    temp_v0 = func_00201DB0((s32)arg0);
    temp_s1 = func_00206C20(temp_v0, arg1, arg2);
    temp_s0 = func_00206A60(temp_v0, arg1, arg2);
    func_00206A50(temp_v0, arg1);
    func_00201D10();
    if (func_0024C7C0(temp_s1, 1) != 0) {
        func_00204B40(arg0, arg1, 0x02000000, 1);
    }
    return temp_s0;
}
