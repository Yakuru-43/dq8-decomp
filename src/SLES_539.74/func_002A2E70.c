// range: 0x2A2E70 0x2A2EC0
#include "common.h"

char *func_00130FD0(char *, const char *, u32);
void func_00131188(char *, s32, s32);
extern s32 D_003DFF1C;
extern char D_00421450[0x2C];

void func_002A2E70(s32 arg0, char *arg1) {
    D_003DFF1C = arg0;
    if (arg1 != NULL) {
        func_00130FD0(D_00421450, arg1, 0x2CU);
    } else {
        func_00131188(D_00421450, 0, 0x2C);
    }
}
