// range: 0x45F870 0x45F880
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    f32 unk0;
    s8 unk4;
} S_arg0;

void func_0045F870(S_arg0 *arg0, s8 arg1, f32 fparg0) {
    arg0->unk0 = fparg0;
    arg0->unk4 = arg1;
}
