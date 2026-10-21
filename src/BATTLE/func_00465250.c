// range: 0x465250 0x465270
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x78];
    s32 unk78;
    char pad7C[0x4];
    s32 unk80;
    s32 unk84;
} S_arg0;

void func_00465250(S_arg0 *arg0) {
    arg0->unk80 = (s32) (arg0->unk78 - 1);
    arg0->unk84 = (s32) (arg0->unk78 - 1);
}
