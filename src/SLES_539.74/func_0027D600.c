// range: 0x27D600 0x27D670
#include "common.h"

extern f32 func_0027D0F0(void *);
extern f32 func_0027E2A0(void *, void *, void *);

f32 func_0027D600(void *a0, void *a1) {
    f32 result;
    f32 divisor;

    divisor = func_0027D0F0(a0);

    if (divisor == 0.0f) {
        return 0.0f;
    }

    result = func_0027E2A0(a0, a1, a0);
    return result / divisor;
}
