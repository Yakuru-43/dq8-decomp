// range: 0x45F830 0x45F840
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    f32 unk0;
    s8 unk4;
} S_arg0;

void func_0045F830(S_arg0 *arg0, s8 arg1, f32 fparg0) {
    arg0->unk0 = fparg0;
    arg0->unk4 = arg1;
}
