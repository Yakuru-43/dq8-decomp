// range: 0x476C80 0x476C90
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x74];
    s32 unk74;
} S_arg0;

void func_00476C80(S_arg0 *arg0, s32 arg1) {
    arg0->unk74 = arg1;
}
