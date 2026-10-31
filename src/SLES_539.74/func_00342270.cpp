// range: 0x342270 0x3422A0
#include "common.h"

extern "C" {

s16 func_00296FA0(void *obj);

s16 func_00342270(void **slot) {
    void *obj = *slot;

    if ((obj != 0) != false) {
        return func_00296FA0(obj);
    }
    return 0;
}

}  // extern "C"
