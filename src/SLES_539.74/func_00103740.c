// range: 0x103740 0x1037A0
// Sibling of func_001034A0/func_00103500: points the handle at D_003DD6D8,
// runs the sub-object constructor func_00102A50 on it, and at n > 0 frees
// the object itself.  Returns obj.
#include "common.h"

extern M2C_UNK D_003DD6D8 __attribute__((section(".data")));

extern void func_00102A50(void *obj, s16 n);
extern void func_001007A0(void *node);

void *func_00103740(void *obj, s16 n) {
    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD6D8;
        func_00102A50(obj, 0);
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
