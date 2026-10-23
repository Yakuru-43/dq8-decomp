// range: 0x211A50 0x211AC0
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

extern char *D_003E0908;
extern s32 D_003E0954;
extern char D_003A58F0[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);
s32 func_00211AC0(char *);

void func_00211A50(s32 arg0, s32 arg1) {
    MsgData msg;

    D_003E0954 = func_00211AC0(D_003E0908 + 0x430);
    func_00166130(&msg);
    func_00166270(&msg, D_003A58F0);
    func_001661A0(&msg, arg0, arg1);
    func_00166420(&msg);
}
