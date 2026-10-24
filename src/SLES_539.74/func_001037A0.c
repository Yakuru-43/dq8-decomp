// range: 0x1037A0 0x1037F0
// Sibling of func_001034A0/func_00103500: re-points the vtable at
// D_003DD710 and, when n > 0, frees the object.  Returns obj.
#include "common.h"

extern M2C_UNK D_003DD710 __attribute__((section(".data")));

extern void func_001007A0(void *node);

void *func_001037A0(void *obj, s16 n) {
    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD710;
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
