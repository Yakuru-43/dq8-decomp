// range: 0x472AA0 0x472AB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x389];
    s8 unk389;
} S_arg0;

s8 func_00472AA0(S_arg0 *arg0) {
    return arg0->unk389;
}
