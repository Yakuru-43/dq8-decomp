// range: 0x3601D0 0x360220
#include "common.h"

extern void *func_003590A0(s32, s32, s32, s32, s32, s32);
extern void func_0035C640(void *, s32);

void func_003601D0(s32 arg0) {
    void *temp_v0;

    if (arg0 == 0) {
        return;
    }
    temp_v0 = func_003590A0(arg0, 0x385, 1, 0, -1, 0);
    if (temp_v0 == NULL) {
        return;
    }
    func_0035C640(temp_v0, 1);
}
