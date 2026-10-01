// range: 0x478B30 0x478B40
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x60];
    s32 unk60;
} S_arg0;

void func_00478B30(S_arg0 *arg0) {
    arg0->unk60 = (s32) (arg0->unk60 + 1);
}
