// range: 0x27D670 0x27D6E0
#include "common.h"

extern f32 func_0027D100(void *);
extern f32 func_0027E2D0(void *, void *, void *);

f32 func_0027D670(void *a0, void *a1) {
    f32 temp;
    f32 result;

    temp = func_0027D100(a0);
    if (temp == 0.0f) {
        return 0.0f;
    }
    result = func_0027E2D0(a0, a1, a0);
    result = result / temp;
    return result;
}
