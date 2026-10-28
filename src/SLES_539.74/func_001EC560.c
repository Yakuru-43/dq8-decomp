// range: 0x1EC560 0x1EC5D0
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

extern s32 D_003E0764;
extern s32 D_003E0770;
extern s32 D_003E07A4;
extern s32 D_003E07A8;
extern char D_003A4D10[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_001EC560(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MsgData msg;

    D_003E0764 = arg0;
    D_003E0770 = arg3;
    D_003E07A4 = 0;
    D_003E07A8 = 0;
    func_00166130(&msg);
    func_00166270(&msg, D_003A4D10);
    func_001661A0(&msg, arg1, arg2);
    func_00166420(&msg);
}
