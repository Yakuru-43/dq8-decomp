// range: 0x30C200 0x30C250
#include "common.h"

s32 func_0030B890(void *, long);       /* extern */
void func_00356910(void *, s32);       /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030C200(void *arg0, S_arg1 *arg1) {
    if (func_0030B890(arg1->unk158, 0x8) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
