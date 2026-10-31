// range: 0x36EED0 0x36EF20
#include "common.h"

void func_001340C0(char *, char *);
void func_0036F0B0(char *);
char *func_00161E80(s32, char *, s32 *);

void func_0036EED0(s32 arg0, char *arg1, s32 *arg2) {
    char sp30[0x100];

    func_001340C0(sp30, arg1);
    func_0036F0B0(sp30);
    func_00161E80(arg0, sp30, arg2);
}
