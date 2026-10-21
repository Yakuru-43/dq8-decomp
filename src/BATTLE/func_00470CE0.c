// range: 0x470CE0 0x470CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x448];
    f32 unk448;
} S_arg0;

void func_00470CE0(S_arg0 *arg0, f32 fparg0) {
    arg0->unk448 = fparg0;
}
