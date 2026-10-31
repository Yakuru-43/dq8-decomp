// range: 0x1AF0A0 0x1AF120
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

typedef struct {
    char pad0[0x20];
    s32 field20;
} ArgStruct;

extern char *D_003E06A0;
extern s32 D_003E06A4;
extern char D_003A1E10[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_001AF0A0(ArgStruct *arg0, s32 arg1, s32 arg2, s32 arg3) {
    MsgData msg;

    if (arg1 != 0 && arg2 != 0) {
        arg0->field20 = 0;
        D_003E06A0 = (char *)arg0;
        D_003E06A4 = arg1;
        func_00166130(&msg);
        func_00166270(&msg, D_003A1E10);
        func_001661A0(&msg, arg2, arg3);
        func_00166420(&msg);
    }
}
