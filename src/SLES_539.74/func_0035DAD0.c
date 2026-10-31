// range: 0x35DAD0 0x35DB30
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002B8090(void);
s32 func_0035F5B0(void);
typedef struct {
    char pad0[0x68];
    s32 unk68;
    char pad6C[0xD4];
    s32 unk140;
    s32 unk144;
    char pad148[0x418];
    s8 unk560;
    u8 unk561;
    char pad562[0x6];
    s32 unk568;
    s16 unk56C;
    s8 unk56E;
    char pad56F[0x2];
    s8 unk571;
} S_arg0;

void func_0035DAD0(S_arg0 *arg0) {
    arg0->unk68 = 0;
    arg0->unk571 = 1;
    arg0->unk560 = 1;
    arg0->unk140 = (s32) arg0->unk144;
    if (arg0->unk561 == 0) {
        arg0->unk56E = 1;
        arg0->unk568 = func_0035F5B0();
        arg0->unk56C = func_002B8090();
    }
}
