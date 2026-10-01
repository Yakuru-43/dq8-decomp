// range: 0x346720 0x346730
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x5380];
    f32 unk5380;
} S_arg0;

void func_00346720(S_arg0 *arg0, f32 fparg0) {
    arg0->unk5380 = fparg0;
}
