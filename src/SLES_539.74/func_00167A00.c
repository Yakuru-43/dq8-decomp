// range: 0x167A00 0x167A50
#include "common.h"

s32 func_00144360(char *);
s32 func_0015F490(void);

f32 func_00167A00(void) {
    s32 v0;
    v0 = func_00144360((char *)func_0015F490());
    if (v0 == 2) {
        return 1.0f;
    }
    return 0.5f;
}
