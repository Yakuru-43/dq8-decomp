// range: 0x212BA0 0x212D20
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

typedef struct {
    char pad0[0x11E8];
    u8 unk11E8;
    char pad11E9[0x1F20 - 0x11E9];
} MsgBig;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} ItemHdr;

extern char *D_003E0908;

char *func_0015F490(void);
void func_001419A0(char *, s32, f32);
char *func_002F6960(char *);
void func_002F6650(void *);
void func_002F6340(void *, s32);
void func_002EEE50(char *, f32, f32);
void func_002F7540(char *, f32);
void func_002E6710(void *, s32);
void func_002E6780(void *, s32, u32);
void func_002E4DC0(void *, s16, s16);
void func_00212D30(void *, s32);
void func_00212D20(void *, s32);
void func_001FF370(void *, s32, s32);
void func_002F60F0(void *);
void func_002E4160(void *, s32);

void func_00212BA0(ItemHdr *item, s8 kind, s32 mode) {
    MsgBig msg;
    s32 t;

    if (item->unk4 == 0) {
        return;
    }
    func_001419A0(func_0015F490(), *(s32 *)(D_003E0908 + 0x5E0), 1.0f);
    func_002F6960((char *)&msg);
    func_002F6650(&msg);
    func_002F6340(&msg, 0);
    func_002EEE50((char *)&msg, -1.0f, -1.0f);
    func_002F7540((char *)&msg, 0.0f);
    func_002E6710(&msg, -4);
    func_00212D30(&msg, 0);
    func_00212D20(&msg, 0);
    func_002E6780(&msg, 0, 0x80092029);
    func_002E6780(&msg, 1, 0x80092029);
    t = item->unk0 - 0x100;
    if (mode != 0) {
        t = t * 12 / 16;
    } else {
        t = t * 12 / 12;
    }
    func_002E4DC0(&msg, (s16)(t + 0x100), item->unk2);
    msg.unk11E8 = kind;
    func_001FF370(&msg, item->unk4, 1);
    func_002F60F0(&msg);
    func_002E4160(&msg, 0);
}
