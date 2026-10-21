// range: 0x47A1F0 0x47A200
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x460];
    s32 unk460;
} S_arg0;

void func_0047A1F0(S_arg0 *arg0, s32 arg1) {
    arg0->unk460 = arg1;
}
