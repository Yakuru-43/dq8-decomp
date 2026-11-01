// range: 0x1F0050 0x1F0100
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_001F0100(void);
f32 func_001F0190(void);

typedef struct {
    char pad0[0x1F8];
    s32 unk1F8;
} S_arg0;

s32 func_001F0050(S_arg0 *arg0) {
    f32 t;
    s32 n = arg0->unk1F8;

    if (n <= 1) {
        return 0;
    }
    if (n != 4) {
        t = func_001F0190() - 9.0f;
        if (t < 0.0f) {
            t += 24.0f;
        }
        return (s32) (t / (24.0f / (f32) n)) % n;
    }
    return func_001F0100();
}
