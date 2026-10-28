// range: 0x342560 0x342590
#include "common.h"

extern "C" {

s32 func_00297080(void *obj);

s32 func_00342560(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00297080(obj);
    }
    return 0;
}

}  // extern "C"
