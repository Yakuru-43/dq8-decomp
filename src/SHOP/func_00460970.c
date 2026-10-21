// range: 0x460970 0x460980
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1CC];
    s32 unk1CC;
} S_arg0;

void func_00460970(S_arg0 *arg0, s32 arg1) {
    arg0->unk1CC = arg1;
}
