// range: 0x222B00 0x222B30
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1];
    s8 unk1;
} S_arg0;

void func_00222B00(S_arg0 *arg0) {
    arg0->unk1 = (s8) (arg0->unk1 + 1);
    if (arg0->unk1 >= 0x15) {
        arg0->unk1 = 0;
    }
}
