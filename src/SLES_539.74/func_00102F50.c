// range: 0x102F50 0x102FB0
#include "common.h"

extern M2C_UNK D_003DD820 __attribute__((section(".data")));
extern M2C_UNK D_003DD7E0 __attribute__((section(".data")));

extern void func_001007A0(void *node);

void *func_00102F50(void *obj, s16 n) {
    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD820;
        if (obj != 0) {
            M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD7E0;
        }
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
