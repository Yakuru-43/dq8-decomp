// range: 0x3422C0 0x3422F0
#include "common.h"

extern "C" {

s32 func_0035DC80(void *obj);

s32 func_003422C0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035DC80(obj);
    }
    return 0;
}

}  // extern "C"
