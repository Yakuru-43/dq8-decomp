// range: 0x30BE80 0x30BEE0
#include "common.h"

s32 func_003101F0(void *, s32, s32, s32);     /* extern */
void func_00356910(void *, s32);               /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030BE80(void *arg0, S_arg1 *arg1) {
    if (func_003101F0(arg1->unk158, 0x4, 0, 0) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
