// range: 0x1B1830 0x1B18E0
#include "common.h"

void func_0014E320(char *);
void func_0014E500(char *, char *);
char *func_0014E360(char *, s32, s32, s32);
s32 func_001629F0(void *, char *, void *);
void func_001B19E0(void *, char *, char *, s32);
extern void *D_003C4160 __attribute__((section(".data")));
extern void *D_00410FA0 __attribute__((section(".data")));

void func_001B1830(char *arg0) {
    void *sp4C;
    char *temp_s0;
    char *temp_s1;

    temp_s0 = *(char **)(arg0 + 0x548);
    if (temp_s0 == 0) {
        return;
    }
    temp_s1 = func_0014E360(temp_s0, 2, 0, 0x40);
    func_0014E320(temp_s0);
    func_0014E500(temp_s0, temp_s1);
    if (func_001629F0(&D_003C4160, temp_s1, &sp4C) != 0) {
        func_001B19E0(&D_00410FA0, arg0, temp_s1, *(s32 *)&sp4C);
    }
}
