// range: 0x30B7E0 0x30B840
#include "common.h"

s32 func_00310050(void *, s32, s32, s32);     /* extern */
void func_00356910(void *, s32);              /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030B7E0(void *arg0, S_arg1 *arg1) {
    if (func_00310050(arg1->unk158, 0x39, 0, 0) != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
