// range: 0x21FB50 0x21FBA0
#include "common.h"

void func_002F7430(char *, s32);
void func_002F7440(char *);
char *func_0018D7D0(s32, s32);

void func_0021FB50(s32 arg0) {
    char *temp_v0;

    temp_v0 = func_0018D7D0(arg0, 5);

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002F7430(temp_v0, 1);
    func_002F7440(temp_v0);
}
