// range: 0x157B80 0x157BC0
#include "common.h"

extern s64 D_003A0F30[12] __attribute__((section(".data")));

void func_00157B80(char *arg0, s32 arg1) {
    if (arg1 >= 0 && arg1 < 0xC) {
        *(s64 *)(arg0 + 0x10) = D_003A0F30[arg1];
    }
}
