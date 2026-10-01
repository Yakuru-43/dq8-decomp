// range: 0x468DE0 0x468DF0
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

void func_00468DE0(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk20 = (s32) arg1->unk20;
}
