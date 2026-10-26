// range: 0x28EF50 0x28EF70
#include "common.h"

void func_0028EF50(u8 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    *(u128 *)(arg0 + 0x2B0) = *(u128 *)(arg0 + 0x260);
    *(f32 *)(arg0 + 0x260) = arg1;
    *(f32 *)(arg0 + 0x264) = arg2;
    *(f32 *)(arg0 + 0x268) = arg3;
}
