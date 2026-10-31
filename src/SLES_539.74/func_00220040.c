// range: 0x220040 0x220070
// auto: m2c, verified byte-exact
#include "common.h"

extern void func_00220070(void *arg0, s32 arg1);

void func_00220040(void *arg0, s32 arg1) {
    s32 diff = M2C_FIELD(arg0, s16 *, 0x44) - arg1;

    if (diff <= 0) {
        return;
    }
    func_00220070(arg0, diff);
}
