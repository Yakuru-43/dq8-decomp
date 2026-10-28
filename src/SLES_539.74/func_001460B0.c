// range: 0x1460B0 0x146100
#include "common.h"

void func_00141C50(char *, char *);
void func_00141C70(char *, s32);

extern u8 D_003A0CE0 __attribute__((section(".data")));

void func_001460B0(char *arg0, s32 arg1) {
    func_00141C50(arg0, (char *)&D_003A0CE0);
    func_00141C70(arg0, arg1);
}
