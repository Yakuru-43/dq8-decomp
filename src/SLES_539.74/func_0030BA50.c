// range: 0x30BA50 0x30BAB0
#include "common.h"

s32 func_0030FE30(void *, s32, s32);          /* extern */
void func_00356910(void *, s32);               /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030BA50(void *arg0, S_arg1 *arg1) {
    if (func_0030FE30(arg1->unk158, 0, 0) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
