// range: 0x341A00 0x341A30
#include "common.h"

extern "C" {

s64 func_0035BFE0(void *obj);

s64 func_00341A00(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_0035BFE0(obj);
    }
    return 0;
}

}  // extern "C"
