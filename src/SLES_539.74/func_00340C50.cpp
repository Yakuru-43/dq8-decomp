// range: 0x340C50 0x340C80
#include "common.h"

extern "C" {

s64 func_0035E320(void *obj);

s64 func_00340C50(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035E320(obj);
    }
    return 0;
}

}  // extern "C"
