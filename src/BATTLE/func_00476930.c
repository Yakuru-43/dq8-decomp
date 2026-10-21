// range: 0x476930 0x476940
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1E4];
    f32 unk1E4;
} S_arg0;

void func_00476930(S_arg0 *arg0, f32 fparg0) {
    arg0->unk1E4 = fparg0;
}
