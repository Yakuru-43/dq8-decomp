// range: 0x149FD0 0x14A030
#include "common.h"

void func_001494A0(char *, char *);
void func_00149B30(char *, s32);

extern s128 D_003ED880;

void func_00149FD0(char *arg0, s128 *arg1, s32 arg2) {
    char sp30[0x40];

    D_003ED880 = *arg1;
    if (arg0[0x28] != 0) {
        func_001494A0(arg0, sp30);
    }
    func_00149B30(arg0, arg2);
}
