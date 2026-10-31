// range: 0x1B5E00 0x1B5E70
#include "common.h"

s32 func_0016DF20(char *, s32);
void func_001EBE00(void *, s32);
extern char *D_003E0664;

s32 func_001B5E00(char *arg0) {
    s32 val;
    void *ret;
    void *temp_a0;

    ret = (void *)func_0016DF20(D_003E0664, *(s32 *)(D_003E0664 + 0x44BC));
    if (ret == 0) {
        return 0;
    }
    temp_a0 = (char *)ret + 0x70;
    if (temp_a0 == 0) {
        return 0;
    }
    if (*(s32 *)(arg0 + 0) == 1) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_001EBE00(temp_a0, val);
    return 1;
}
