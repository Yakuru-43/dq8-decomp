// range: 0x35D880 0x35D8F0
// flags: -O3 -flag divbyzerocheck
#include "common.h"

extern s32 func_00132D38(void);

typedef struct {
    char pad[0x9C];
    s32 flags;
} Struct0035D880;

s32 func_0035D880(Struct0035D880 *arg0) {
    s32 s0;
    s32 s1;
    s32 range;
    s32 r;

    s1 = 0;
    s0 = 0;
    if (arg0->flags & 8) {
        s0 = 2;
        s1 = 6;
    }
    range = (s1 - s0) + 1;
    r = func_00132D38() % range;
    return s0 + r;
}
