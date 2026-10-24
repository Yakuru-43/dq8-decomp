// range: 0x304D30 0x304FE0
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x4054];
    s32 unk4070;
} S_obj;

typedef struct {
    s32 unk0;
    s32 unk4;
    char pad8[4];
    s32 unkC;
    char pad10[0x10];
    s32 unk20;
    s32 unk24[4];
    char pad34[0x10];
    s32 unk44[4];
    char pad54[0x14];
    s32 unk68;
    s32 unk6C;
    s32 unk70[4];
    s32 unk80[4];
} S_evt;

s32 func_001814D0(void);
s32 func_00191EB0(s32);
s32 func_00308C70(s32);
s32 func_00308B50(s32, s32);
s32 func_00304600(s32, s32);
void func_003040A0(s32, s32, s32);
void func_003050A0(void *, s32, s32);
void func_00305060(void *, s32);
void func_00305160(void *, s32, s32);
s32 func_003051C0(void *, s32);
s32 func_002C17F0(void);
s32 func_002B90D0(void);
s32 func_003053E0(void);

void func_00304D30(S_obj *obj, S_evt *arg1) {
    S_evt local;
    s32 party;
    s32 handle;
    s32 actor;
    s32 i;
    s32 count;
    s32 amt;

    local = *arg1;
    party = func_00191EB0(func_001814D0());
    handle = func_00308C70(party);
    actor = func_00304600(handle, func_00308B50(party, func_00308C70(party)));
    switch (local.unk0) {
    case 2:
        if (local.unkC == 0) {
            if (obj->unkC < 999999) {
                obj->unkC = obj->unkC + 1;
            }
        } else {
            if (obj->unk10 < 999999) {
                obj->unk10 = obj->unk10 + 1;
            }
        }
        func_003051C0(obj, local.unk68);
        for (i = 0; i < 4; i++) {
            func_003050A0(obj, local.unk70[i], local.unk80[i]);
        }
        break;
    case 3:
        if (obj->unk14 < 999999) {
            obj->unk14 = obj->unk14 + 1;
        }
        func_003040A0(actor, 1, 1);
        if (local.unk4 > 0) {
            break;
        }
        if (obj->unk4070 < 999999) {
            obj->unk4070 = obj->unk4070 + 1;
        }
        break;
    case 1:
        if (obj->unk18 < 0xFFFF) {
            obj->unk18 = obj->unk18 + 1;
        }
        func_003040A0(actor, 2, 1);
        break;
    case 5:
        if (obj->unkC < 999999) {
            obj->unkC = obj->unkC + 1;
        }
        break;
    }
    if (func_002C17F0() != 0) {
        if (func_002B90D0() == 0) {
            if (local.unk0 == 1) {
                return;
            }
        }
    }
    if (func_003053E0() != 0) {
        return;
    }
    count = local.unk20;
    for (i = 0; i < count; i++) {
        amt = local.unk44[i];
        func_00305060(obj, amt);
        func_00305160(obj, local.unk24[i], amt);
    }
}
