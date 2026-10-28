// range: 0x149410 0x149460
#include "common.h"

void func_001494A0(char *, char *);
int func_0013C610();

void func_00149410(char *arg0, void *arg1, void *arg2) {
    char sp30[0x40];

    func_001494A0(arg0, sp30);
    func_0013C610(arg1, sp30, arg2);
}
