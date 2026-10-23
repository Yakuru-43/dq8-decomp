// range: 0x2127E0 0x212850
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x14];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    char text[0xED0 - 0x34];
} MsgData;

extern u8 D_003E094C;
extern char D_003A5830[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_002127E0(s32 arg0, s32 arg1) {
    MsgData msg;

    if (arg0 == 0 || arg1 <= 0) {
        return;
    }
    D_003E094C = 0;
    func_00166130(&msg);
    func_00166270(&msg, D_003A5830);
    func_001661A0(&msg, arg0, arg1);
    func_00166420(&msg);
}
