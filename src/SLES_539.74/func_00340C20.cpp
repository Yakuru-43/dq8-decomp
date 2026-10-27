// range: 0x340C20 0x340C50
#include "common.h"

extern "C" {

s32 func_0035E2E0(void *obj);

s32 func_00340C20(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035E2E0(obj);
    }
    return 0;
}

}  // extern "C"
