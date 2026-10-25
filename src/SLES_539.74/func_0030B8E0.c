// range: 0x30B8E0 0x30B960
#include "common.h"

s32 func_00296F10(void *);             /* extern */
void func_00356910(void *, s32);        /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030B8E0(void *arg0, S_arg1 *arg1) {
    if (func_00296F10(arg1->unk158) == 4) {
        func_00356910(arg0, 1);
        return;
    }
    if (func_00296F10(arg1->unk158) == 6) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
