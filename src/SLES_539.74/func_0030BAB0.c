// range: 0x30BAB0 0x30BB10
#include "common.h"

s32 func_0030FE50(void *, s32, s32);          /* extern */
void func_00356910(void *, s32);               /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030BAB0(void *arg0, S_arg1 *arg1) {
    if (func_0030FE50(arg1->unk158, 0, 0) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
