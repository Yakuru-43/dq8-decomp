// range: 0x341C40 0x341C70
#include "common.h"

extern "C" {

s32 func_0035BE70(void *obj, s32 n);

s32 func_00341C40(void **slot, s32 n) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035BE70(obj, n);
    }
    return 0;
}

}  // extern "C"
