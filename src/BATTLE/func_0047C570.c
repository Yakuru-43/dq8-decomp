// range: 0x47C570 0x47C580
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2C];
    s32 unk2C;
} S_arg0;

s32 func_0047C570(S_arg0 *arg0) {
    return arg0->unk2C;
}
