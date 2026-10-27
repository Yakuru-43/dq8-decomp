// range: 0x3423E0 0x342410
#include "common.h"

extern "C" {

s32 func_00296FF0(void *obj);

s32 func_003423E0(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296FF0(obj);
    }
    return 0;
}

}  // extern "C"
