// range: 0x3424A0 0x3424D0
#include "common.h"

extern "C" {

s32 func_00296FC0(void *obj);

s32 func_003424A0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296FC0(obj);
    }
    return 0;
}

}  // extern "C"
