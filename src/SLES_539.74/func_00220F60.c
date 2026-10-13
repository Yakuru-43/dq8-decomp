// range: 0x220F60 0x220FB0
#include "common.h"

extern void func_002E6550(void *arg0, void *arg1, s32 *out0, s32 *out1);

/* asks func_002E6550 for two integer values and hands back the float versions */
void func_00220F60(void *arg0, void *arg1, float *out0, float *out1) {
    s32 raw0;
    s32 raw1;

    func_002E6550(arg0, arg1, &raw0, &raw1);
    *out0 = (float)raw0;
    *out1 = (float)raw1;
}
