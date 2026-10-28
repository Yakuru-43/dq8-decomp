// range: 0x1EE950 0x1EE9C0
#include "common.h"

extern void func_00166700(f32 *out, s32 id);
extern void func_001E9FB0(char *obj, f32 *v);
extern char *func_001EE7E0(void *);
extern void *D_003E076C;

s32 func_001EE950(s32 arg0) {
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
    func_001E9FB0(obj, vec);
    return 1;
}
