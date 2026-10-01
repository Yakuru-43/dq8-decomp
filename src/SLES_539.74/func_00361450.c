// range: 0x361450 0x361480
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2];
    s16 unk2;
    s16 unk4;
    char pad6[0x6];
    s16 unkC;
    s16 unkE;
    char pad10[0x34];
    s16 unk44;
    char pad46[0x6];
    s16 unk4C;
} S_arg1;

void func_00361450(s32 arg0, S_arg1 *arg1) {
    if (arg1 != NULL) {
        arg1->unk4 = -1;
        arg1->unk2 = -1;
        arg1->unkC = 0;
        arg1->unkE = 0;
        arg1->unk44 = 0;
        arg1->unk4C = 0;
    }
}
