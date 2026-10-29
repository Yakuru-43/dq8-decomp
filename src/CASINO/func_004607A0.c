// range: 0x4607A0 0x460830
#include "common.h"

extern u32 func_1341D8(char *);

typedef struct {
    char pad0[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} S_arg0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} S_vals;

extern void func_1340C0(S_arg0 *arg0, char *str);

void func_004607A0(S_arg0 *arg0, char *arg1, S_vals *arg2) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (arg1 == 0) {
        return;
    }
    if (func_1341D8(arg1) > 0x20) {
        return;
    }
    func_1340C0(arg0, arg1);
    a = arg2->unk8;
    b = arg2->unkC;
    c = arg2->unk0;
    d = arg2->unk4;
    arg0->unk24 = d;
    arg0->unk20 = c;
    arg0->unk28 = a;
    arg0->unk2C = b;
}
