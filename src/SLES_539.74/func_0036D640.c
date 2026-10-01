// range: 0x36D640 0x36D670
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x580];
    s8 unk580;
    s8 unk581;
    char pad582[0x2];
    s32 unk584;
    s16 unk588;
} S_arg0;

void func_0036D640(S_arg0 *arg0) {
    arg0->unk580 = 1;
    arg0->unk581 = 1;
    arg0->unk584 = -1;
    if (arg0->unk588 == 3) {
        arg0->unk588 = 1;
    }
}
