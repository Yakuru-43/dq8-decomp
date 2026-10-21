// range: 0x20BF90 0x20BFE0
#include "common.h"

void func_0020BF90(char *arg0, s32 arg1) {
    s32 idx;
    char *p;

    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        p = 0;
    } else {
        p = arg0 + idx * 0xC0 + 0x5610;
    }
    M2C_FIELD(p, f32 *, 0x20) = -M2C_FIELD(p, f32 *, 0x1C) / (f32)arg1;
    M2C_FIELD(p, s32 *, 0x24) = 0;
}
