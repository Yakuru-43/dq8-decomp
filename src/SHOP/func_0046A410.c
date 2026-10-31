// range: 0x46A410 0x46A4C0
#include "common.h"

extern char *func_0046DDF0(s32);
extern void func_2D5230(char *, s32, s32, s32);

void func_0046A410(s32 arg0, s32 *arg1) {
    char *temp_v0;
    s32 temp_s0;

    temp_v0 = func_0046DDF0(arg0);
    temp_s0 = arg0 + 4;
    func_2D5230(temp_v0, temp_s0, 0, arg1[0]);
    func_2D5230(temp_v0, temp_s0, 1, arg1[1]);
    func_2D5230(temp_v0, temp_s0, 2, arg1[2]);
    func_2D5230(temp_v0, temp_s0, 3, arg1[3]);
    func_2D5230(temp_v0, temp_s0, 4, arg1[4]);
}
