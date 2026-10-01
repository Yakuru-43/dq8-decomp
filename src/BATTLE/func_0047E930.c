// range: 0x47E930 0x47E950
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x20];
    s8 unk28;
} S_arg0;

void func_0047E930(S_arg0 *arg0) {
    if (arg0->unk28 != 0) {
        arg0->unk4 = 0;
    }
}
