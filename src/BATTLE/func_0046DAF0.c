// range: 0x46DAF0 0x46DB20
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2DEC];
    s32 unk2DEC;
    char pad2DF0[0x60];
    s32 unk2E50;
} S_arg0;

void func_0046DAF0(S_arg0 *arg0) {
    if (arg0->unk2E50 == 0) {
        arg0->unk2DEC = (s32) (arg0->unk2DEC + 1);
    }
}
