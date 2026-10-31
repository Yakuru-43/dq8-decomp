// range: 0x1EE8E0 0x1EE950
#include "common.h"

extern void func_00166700(f32 *out, s32 id);
extern void func_001E9F20(char *obj, f32 *v);
extern char *func_001EE7E0(void *);
extern void *D_003E076C;

s32 func_001EE8E0(s32 arg0) {
    f32 vec[4];
    char *obj;

    if (D_003E076C == 0) {
        return 0;
    }
    obj = func_001EE7E0(D_003E076C);
    if (obj == 0) {
        return 0;
    }
    func_00166700(vec, arg0);
    func_001E9F20(obj, vec);
    return 1;
}
