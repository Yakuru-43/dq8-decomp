// range: 0x46BC70 0x46BC80
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x21C];
    s32 unk21C;
} S_arg0;

void func_0046BC70(S_arg0 *arg0, s32 arg1) {
    arg0->unk21C = arg1;
}
