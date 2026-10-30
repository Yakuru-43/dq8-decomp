// range: 0x3425C0 0x342680
#include "common.h"

s32 func_002983C0(void *, s32, void *);
s32 func_002B0050(void *, s32);
extern u8 D_0042CDB0[];
extern u8 D_004392A0[];

s32 func_003425C0(s32 arg0, void *arg1, s32 *arg2) {
    s32 temp_v0;
    s32 i;
    u32 addr;
    u16 count;
    u8 flag;

    *arg2 = 0;
    temp_v0 = func_002B0050(D_004392A0, arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        addr = temp_v0 + (i << 1);
        count = *(u16 *)(addr + 0x48);
        if (count <= 0) {
            continue;
        }
        flag = *(u8 *)(temp_v0 + i + 0x4C);
        if (flag != 0) {
            continue;
        }
        *arg2 = 1;
        return 0;
    }
    return func_002983C0(D_0042CDB0, arg0, arg1);
}
