// range: 0x328200 0x328220
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 *D_003E1214;
extern s8 *D_003E1218;
extern s32 D_003E1220;
extern s32 D_003E1224;

void func_00328200(void) {
    D_003E1218 = D_003E1214;
    if (D_003E1214 != NULL) {
        *D_003E1214 = 0;
    }
    D_003E1220 = 0;
    D_003E1224 = 0;
}
