// range: 0x466AA0 0x466AB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x174];
    s32 unk174;
    s32 unk178;
} S_arg0;

void func_00466AA0(S_arg0 *arg0) {
    arg0->unk174 = 0xBF800000;
    arg0->unk178 = 0xBF800000;
}
