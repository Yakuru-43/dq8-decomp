// range: 0x177920 0x177A70
#include "common.h"

char * func_0016D5B0(char *, s32);
s32 func_00302F40(char *);
s32 func_0016B7E0(char *, s32, s32);
s32 func_0016CFA0(char *, s32, s32, s32);

s32 func_00177920(char *arg0, s32 arg1, char *arg2, s32 arg3) {
    s32 var_s3;
    s32 var_s4;
    s32 var_s2;
    s32 temp_v0;
    char *temp_v0_2;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v0_2 = func_0016D5B0(arg0, arg1);
    if (temp_v0_2 == NULL) {
        return 0;
    }
    temp_v0 = *(s32 *)((char *)temp_v0_2 + 0x774);
    var_s3 = 0;
    var_s4 = 0;
    if (temp_v0 == 0xC) {
        return temp_v0;
    }
    if (arg3 & 4) {
        return -1;
    }
    if (func_0016B7E0(arg0, 1, arg1) != 0) {
        if (arg2 != NULL) {
            var_s3 = func_00302F40(arg2);
        }
    }
    if (arg3 & 1) {
        var_s4 = 1;
    }
    if (arg3 & 2) {
        var_s3 = 0;
    }
    func_0016CFA0(arg0, arg1, var_s3, var_s4);
    if (arg1 < 4) {
        var_s2 = 0;
        do {
            func_0016CFA0(arg0, var_s2 + ((arg1 * 3) + 8), var_s3, var_s4);
            var_s2 += 1;
        } while (var_s2 < 3);
    }
    return var_s3;
}
