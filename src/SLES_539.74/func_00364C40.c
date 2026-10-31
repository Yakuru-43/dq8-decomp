// range: 0x364C40 0x364CE0
#include "common.h"

extern s32 func_0033E980(s32);
extern s32 func_003643C0(char *);
extern void func_001339E0(s32, s32);
extern void func_0036CD90(char *, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_00364C40(char *arg0, char *arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg2 <= 0) {
        return;
    }
    if (arg2 != 0xE4) {
        goto epilogue_tail;
    }
    temp_s0 = func_003643C0(arg0);
    temp_v0 = func_0033E980(0x101);
    func_001339E0(temp_s0, temp_v0);
    func_0036CD90(arg0, *(s32 *)(arg1 + 4), *(s32 *)(arg1 + 0x10), 0,
                  0, 1, temp_s0, 6, 0, 0);
epilogue_tail:
    return;
}
