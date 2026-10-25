// range: 0x30BF50 0x30BFC0
#include "common.h"

s32 func_00296FD0(void *);                     /* extern */
s32 func_00296FE0(void *);                     /* extern */
void func_00356910(void *, s32);               /* extern */

typedef struct {
    char pad0[0x158];
    void *unk158;
} S_arg1;

void func_0030BF50(void *arg0, S_arg1 *arg1) {
    s32 a = func_00296FD0(arg1->unk158);
    s32 b = func_00296FE0(arg1->unk158);
    if (b < a) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
