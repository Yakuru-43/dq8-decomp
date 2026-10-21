// range: 0x47BA00 0x47BA10
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2DEC];
    s32 unk2DEC;
} S_arg0;

void func_0047BA00(S_arg0 *arg0) {
    arg0->unk2DEC = 0;
}
