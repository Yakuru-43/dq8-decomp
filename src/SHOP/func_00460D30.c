// range: 0x460D30 0x460D40
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x58];
    s32 unk58;
} S_arg0;

s32 func_00460D30(S_arg0 *arg0) {
    return arg0->unk58;
}
