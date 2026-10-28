// range: 0x342020 0x342050
#include "common.h"

extern "C" {

s32 func_0035E590(void *obj);

s32 func_00342020(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035E590(obj);
    }
    return 0;
}

}  // extern "C"
