// range: 0x30BE20 0x30BE80
#include "common.h"

s32 func_0030B890(void *, long);       /* extern */
void func_00356910(void *, s32);       /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030BE20(void *arg0, S_arg1 *arg1) {
    if (func_0030B890(arg1->unk158, 0x800004000) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
