// range: 0x3396A0 0x3396D0
#include "common.h"

s32 func_00166760();
extern void *D_003E1240;

s32 func_003396A0(void) {
    if (D_003E1240 == NULL) {
        return 0;
    }
    func_00166760();
    return 1;
}
