// range: 0x45F0D0 0x45F0E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg1;

void func_0045F0D0(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk20 = (s32) arg1->unk20;
}
