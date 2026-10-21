// range: 0x468E20 0x468E30
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

void func_00468E20(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk20 = (s32) arg1->unk20;
}
