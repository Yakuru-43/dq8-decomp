// range: 0x287E70 0x287ED0
#include "common.h"

void func_0028C730(char *);

void func_00287E70(char *arg0) {
    s32 i;

    i = 0;
    while (i < *(s32 *)(arg0 + 0x204)) {
        func_0028C730(*(char **)(arg0 + 0x208) + i * 0x170);
        i++;
    }
}
