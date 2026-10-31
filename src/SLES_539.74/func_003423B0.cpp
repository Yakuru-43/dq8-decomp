// range: 0x3423B0 0x3423E0
#include "common.h"

extern "C" {

s32 func_00296FD0(void *obj);

s32 func_003423B0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296FD0(obj);
    }
    return 0;
}

}  // extern "C"
