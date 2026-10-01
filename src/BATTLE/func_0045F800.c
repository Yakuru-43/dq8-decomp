// range: 0x45F800 0x45F810
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x5];
    s8 unk5;
} S_arg0;

void func_0045F800(S_arg0 *arg0) {
    arg0->unk5 = 1;
}
