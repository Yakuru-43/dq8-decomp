// range: 0x462CE0 0x462CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4DC];
    s32 unk4DC;
} S_arg0;

s32 func_00462CE0(S_arg0 *arg0) {
    return arg0->unk4DC;
}
