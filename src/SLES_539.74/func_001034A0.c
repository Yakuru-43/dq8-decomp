// range: 0x1034A0 0x103500
#include "common.h"

extern M2C_UNK D_003DD750 __attribute__((section(".data")));
extern M2C_UNK D_003DD710 __attribute__((section(".data")));

extern void func_001007A0(void *node);

void *func_001034A0(void *obj, s16 n) {
    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD750;
        if (obj != 0) {
            M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD710;
        }
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
