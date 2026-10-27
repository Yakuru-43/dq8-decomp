// range: 0x342470 0x3424A0
#include "common.h"

extern "C" {

s32 func_00296FB0(void *obj);

s32 func_00342470(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296FB0(obj);
    }
    return 0;
}

}  // extern "C"
