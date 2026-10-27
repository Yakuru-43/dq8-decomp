// range: 0x342410 0x342440
#include "common.h"

extern "C" {

s32 func_00297000(void *obj);

s32 func_00342410(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00297000(obj);
    }
    return 0;
}

}  // extern "C"
