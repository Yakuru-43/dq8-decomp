// range: 0x230CC0 0x230D00
#include "common.h"

extern void func_00166700(f32 *out, s32 id);
extern void func_001E9EC0(char *obj, f32 *v);

s32 func_00230CC0(s32 arg0, s32 arg1, char **arg2) {
    f32 vec[4];
    char *obj;

    obj = arg2[0];
    func_00166700(vec, arg0);
    vec[3] = 0.0f;
    func_001E9EC0(obj + 0x5C, vec);
    return 1;
}
