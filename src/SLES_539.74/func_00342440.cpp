// range: 0x342440 0x342470
#include "common.h"

extern "C" {

s32 func_00297020(void *obj);

s32 func_00342440(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00297020(obj);
    }
    return 0;
}

}  // extern "C"
