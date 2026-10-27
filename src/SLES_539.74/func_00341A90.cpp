// range: 0x341A90 0x341AC0
#include "common.h"

extern "C" {

s32 func_0035C190(void *obj, s32 *n);

s32 func_00341A90(void **slot, s32 *n) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035C190(obj, n);
    }
    return 0;
}

}  // extern "C"
