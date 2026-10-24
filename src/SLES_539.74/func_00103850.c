// range: 0x103850 0x1038A0
// Sibling of func_001034A0/func_00103500: re-points the vtable at
// D_003DD7E0 and, when n > 0, frees the object.  Returns obj.
#include "common.h"

extern M2C_UNK D_003DD7E0 __attribute__((section(".data")));

extern void func_001007A0(void *node);

void *func_00103850(void *obj, s16 n) {
    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD7E0;
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
