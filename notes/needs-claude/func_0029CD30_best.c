// best attempt for func_0029CD30 (score 8, not committed as src)
// range: 0x29CD30 0x29CDA0
#include "common.h"

extern "C" {

typedef struct {
    char pad0[0x10];
    s16 count;
} S_cnt;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    char pad3[0x1C - 3];
    S_cnt *cnt;
} S_a;

s32 func_00297090(S_cnt *cnt);

s32 func_0029CD30(s32 arg0, S_a *arg1) {
    S_cnt *cnt;
    s32 count;

    if (arg1->unk0 == 0) {
        return 0;
    }
    if (arg1->unk1 != 0) {
        return 0;
    }
    if (arg1->unk2 != 0) {
        return 0;
    }
    cnt = arg1->cnt;
    count = cnt->count;
    if ((count < 2) == false) {
        if (count < 6) {
            return 0 < func_00297090(cnt);
        }
    }
    return 0;
}

}
