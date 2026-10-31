// range: 0x230D40 0x230D90
#include "common.h"

extern void func_00166700(f32 *out, s32 id);
extern void func_001E9FB0(char *obj, f32 *v);

s32 func_00230D40(s32 arg0, s32 arg1, char **arg2) {
    f32 vec[4];
    char *obj;

    obj = arg2[0];
    func_00166700(vec, arg0);
    vec[3] = 1.0f;
    func_001E9FB0(obj + 0x5C, vec);
    return 1;
}
