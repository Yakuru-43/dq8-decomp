// range: 0x338F60 0x338F90
#include "common.h"

s32 func_00166760();
extern void *D_003E1250;

s32 func_00338F60(void) {
    if (D_003E1250 == NULL) {
        return 0;
    }
    func_00166760();
    return 1;
}
