// range: 0x340C80 0x340CB0
#include "common.h"

extern "C" {

s32 func_0035BF00(void *obj, s32 n);

s32 func_00340C80(void **slot, s32 n) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035BF00(obj, n);
    }
    return 0;
}

}  // extern "C"
