// range: 0x18D1F0 0x18D2C0
#include "common.h"

void func_0014DF10(char *, char *, s32);
void func_0014E320(char *);
void func_0014E500(char *, char *);
void func_00176500(s32);
char *func_0014E360(char *, s32, s32, s32);
s32 func_001629F0(void *, char *, void *);
s32 func_00174B80(s32, char *, char *);
extern void *D_003C30D0 __attribute__((section(".data")));

void func_0018D1F0(char *arg0, s32 arg1) {
    void *sp4C;
    char *temp_s0;
    char *var_s1;

    if (arg1 == 0) {
        temp_s0 = *(char **)(arg0 + 0x548);
        if (temp_s0 != 0) {
            var_s1 = func_0014E360(temp_s0, 2, 0, 0x40);
            func_0014E320(temp_s0);
            func_0014E500(temp_s0, var_s1);
        } else {
            var_s1 = 0;
        }
        func_00176500(7);
        if (func_001629F0(&D_003C30D0, var_s1, &sp4C) != 0) {
            func_0014DF10(arg0 + 0x4D00, arg0 + 0x4500, 0x80);
            *(s32 *)(arg0 + 0x44F0) = func_00174B80(7, var_s1, arg0 + 0x4D00);
        }
    }
}
