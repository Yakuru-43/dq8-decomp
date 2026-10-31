// range: 0x193EE0 0x193F00
#include "common.h"

extern s8 D_003E05B4;
extern char D_0040FD20[0x194];
void func_00130FD0(char *, char *, u32);

void func_00193EE0(char *arg0) {
    D_003E05B4 = 1;
    func_00130FD0(D_0040FD20, arg0, 0x194);
}
