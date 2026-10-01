// range: 0x35DB30 0x35DB60
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
} S_arg0;

s32 func_0035DB30(S_arg0 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = arg0->unk68;
    arg0->unk68 = (s32) arg0->unk64;
    if (arg1 != NULL) {
        *arg1 = arg0->unk68 - temp_v1;
    }
    return arg0->unk68;
}
