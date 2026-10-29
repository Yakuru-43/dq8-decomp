// range: 0x287F40 0x287FA0
#include "common.h"

void func_0028C750(char *);

void func_00287F40(char *arg0) {
    s32 i;

    i = 0;
    while (i < *(s32 *)(arg0 + 0x204)) {
        func_0028C750(*(char **)(arg0 + 0x208) + i * 0x170);
        i++;
    }
}
