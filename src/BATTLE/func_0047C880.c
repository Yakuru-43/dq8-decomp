// range: 0x47C880 0x47C890
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x32];
    s16 unk32;
} S_arg0;

void func_0047C880(S_arg0 *arg0, s32 arg1) {
    arg0->unk32 = (s16) (arg1 != 0);
}
