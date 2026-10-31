// range: 0x342210 0x342240
#include "common.h"

extern "C" {

s32 func_0035DD40(void *obj);

s32 func_00342210(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035DD40(obj);
    }
    return 0;
}

}  // extern "C"
