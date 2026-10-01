// range: 0x462CA0 0x462CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x564];
    s8 unk564;
} S_arg0;

s8 func_00462CA0(S_arg0 *arg0) {
    return arg0->unk564;
}
