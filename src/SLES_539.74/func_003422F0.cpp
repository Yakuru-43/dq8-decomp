// range: 0x3422F0 0x342320
#include "common.h"

extern "C" {

s32 func_0035D530(void *obj);

s32 func_003422F0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035D530(obj);
    }
    return 0;
}

}  // extern "C"
