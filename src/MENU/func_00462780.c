// range: 0x462780 0x462790
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x464];
    s32 unk464;
} S_arg0;

void func_00462780(S_arg0 *arg0, s32 arg1) {
    arg0->unk464 = (s32) (arg1 + 1);
}
