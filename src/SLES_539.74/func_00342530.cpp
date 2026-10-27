// range: 0x342530 0x342560
#include "common.h"

extern "C" {

s32 func_00297030(void *obj);

s32 func_00342530(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00297030(obj);
    }
    return 0;
}

}  // extern "C"
