// range: 0x190A10 0x190A60
#include "common.h"

M2C_UNK func_00151A20(void *, f32 *);

void func_00190A10(void *a0, f32 arg1, f32 arg2, f32 arg3) {
    f32 buf[4];
    u8 *p;
    u32 i;

    p = (u8 *)&buf[0];
    i = 0x10;
    if (p != NULL) {
        do {
            *p = 0;
            i--;
            p++;
        } while (i != 0);
    }
    buf[0] = arg1;
    buf[1] = arg2;
    buf[2] = arg3;
    func_00151A20(a0, buf);
}
