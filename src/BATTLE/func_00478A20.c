// range: 0x478A20 0x478A30
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x30];
    s16 unk30;
} S_arg0;

s16 func_00478A20(S_arg0 *arg0) {
    return arg0->unk30;
}
