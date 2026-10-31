// range: 0x342590 0x3425C0
#include "common.h"

extern "C" {

s32 func_002970C0(void *obj);

s32 func_00342590(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_002970C0(obj);
    }
    return 0;
}

}  // extern "C"
