// range: 0x2648E0 0x264930
#include "common.h"

void func_0013B720(f32 *, f32 *);

void func_002648E0(f32 *arg0, f32 *arg1) {
    f32 *temp_a0;

    *arg0 = 0.0f;
    if (arg1 != NULL) {
        arg0[0] = arg1[4];
        arg0[4] = arg1[5];
        arg0[5] = arg1[6];
        arg0[6] = arg1[7];
        arg0[7] = 0.0f;
        temp_a0 = arg0 + 4;
        func_0013B720(temp_a0, temp_a0);
    }
}
