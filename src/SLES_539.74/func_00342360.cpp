// range: 0x342360 0x342390
#include "common.h"

extern "C" {

s32 func_0035D590(void *obj);

s32 func_00342360(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035D590(obj);
    }
    return 0;
}

}  // extern "C"
