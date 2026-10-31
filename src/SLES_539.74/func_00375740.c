// range: 0x375740 0x3757C0
#include "common.h"

void func_00375740(f32 *arg0, f32 *arg1, s32 arg2) {
    s32 i;
    s32 off;

    if (arg2 == 0) {
        i = 0;
        do {
            off = i << 2;
            *(f32 *)((char *)arg1 + off) = *(f32 *)((char *)arg0 + off + 4);
            i++;
        } while (i < 4);
    } else if (arg2 == 1) {
        i = 0;
        do {
            off = i << 2;
            *(f32 *)((char *)arg1 + off) = *(f32 *)((char *)arg1 + off) * *(f32 *)((char *)arg0 + off + 4);
            i++;
        } while (i < 4);
    }
}
