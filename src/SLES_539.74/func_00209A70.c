// range: 0x209A70 0x209BE0
#include "common.h"

void func_0014DF10(char *, char *, s32);
void func_001746D0(s32);
void func_00176500(s32);
void func_0020CF90(char *);
s32 func_00174B80(s32, void *, char *);

s32 func_00209A70(char *arg0, s32 arg1, void *arg2) {
    char *temp_a1;
    char *temp_a1_2;
    s32 var_v0;

    if (arg1 < 0) {
        var_v0 = 0;
    } else {
        var_v0 = *(s32 *)(arg0 + 0x6414) != arg1;
    }
    if (var_v0 == 0) {
        return 0;
    }
    *(s32 *)(arg0 + 0x6410) = -1;
    *(s32 *)(arg0 + 0x6414) = -1;
    temp_a1 = *(char **)(arg0 + 0x6418);
    if (temp_a1 == 0) {
        func_0014DF10(arg0 + 0x641C, 0, 0);
    } else {
        func_0014DF10(arg0 + 0x641C, temp_a1, 0x180);
    }
    func_001746D0(3);
    func_00176500(3);
    func_001746D0(9);
    *(s32 *)(arg0 + 0x6474) = -1;
    *(s32 *)(arg0 + 0x6478) = -1;
    temp_a1_2 = *(char **)(arg0 + 0x647C);
    if (temp_a1_2 == 0) {
        func_0014DF10(arg0 + 0x6480, 0, 0);
    } else {
        func_0014DF10(arg0 + 0x6480, temp_a1_2, 0x38C);
    }
    func_00176500(9);
    func_001746D0(2);
    func_0020CF90(arg0);
    *(s32 *)(arg0 + 0x5F98) = -1;
    *(s32 *)(arg0 + 0x5F9C) = -1;
    func_0014DF10(arg0 + 0x63A0, arg0 + 0x5FA0, 0x40);
    func_00176500(2);
    *(s32 *)(arg0 + 0x6400) = 0;
    *(s32 *)(arg0 + 0x63F8) = 0;
    *(s32 *)(arg0 + 0x6404) = 0x3F800000;
    *(s32 *)(arg0 + 0x63FC) = -1;
    *(s32 *)(arg0 + 0x6408) = 0;
    *(s32 *)(arg0 + 0x640C) = 0;
    func_0020CF90(arg0);
    *(s32 *)(arg0 + 0x6410) = func_00174B80(3, arg2, arg0 + 0x641C);
    if (*(s32 *)(arg0 + 0x6410) < 0) {
        return 0;
    }
    *(s32 *)(arg0 + 0x6414) = arg1;
    return 1;
}
