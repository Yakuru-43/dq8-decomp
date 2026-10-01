// range: 0x47AD70 0x47AD80
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x260];
    s32 unk260;
} S_arg0;

void func_0047AD70(S_arg0 *arg0, s32 arg1) {
    arg0->unk260 = arg1;
}
