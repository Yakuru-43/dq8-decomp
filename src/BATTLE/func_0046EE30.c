// range: 0x46EE30 0x46EE50
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x138];
    s32 unk138;
    char pad13C[0x4];
    s32 unk140;
    s32 unk144;
    s32 unk148;
} S_arg0;

void func_0046EE30(S_arg0 *arg0) {
    arg0->unk140 = 0;
    arg0->unk144 = 0;
    arg0->unk148 = 0;
    arg0->unk138 = 0;
}
