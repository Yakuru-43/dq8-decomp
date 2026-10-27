// range: 0x3424D0 0x342500
#include "common.h"

extern "C" {

s32 func_00296F70(void *obj);

s32 func_003424D0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296F70(obj);
    }
    return 0;
}

}  // extern "C"
