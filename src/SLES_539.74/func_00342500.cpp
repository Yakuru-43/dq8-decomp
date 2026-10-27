// range: 0x342500 0x342530
#include "common.h"

extern "C" {

s32 func_00296F80(void *obj);

s32 func_00342500(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296F80(obj);
    }
    return 0;
}

}  // extern "C"
