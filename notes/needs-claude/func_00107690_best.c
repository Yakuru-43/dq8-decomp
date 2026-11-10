// best attempt for func_00107690 (score 25, wall: cold delete block placement)
// range: 0x107690 0x107730
#include "common.h"

extern M2C_UNK D_003DD670 __attribute__((section(".data")));
extern M2C_UNK D_003DD870 __attribute__((section(".data")));
extern M2C_UNK D_003DD880 __attribute__((section(".data")));

extern void func_00102B90(void *entry, s16 n);
extern void func_001007A0(void *node);

void *func_00107690(void *obj, s16 n) {
    void *entry;

    if (obj != 0) {
        M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD870;
        if (obj != 0) {
            entry = (char *)obj + 4;
            M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD880;
            if (entry != 0) {
                func_00102B90(entry, -1);
            }
            if (obj != 0) {
                M2C_FIELD(obj, M2C_UNK **, 0) = &D_003DD670;
            }
        }
        if (n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
