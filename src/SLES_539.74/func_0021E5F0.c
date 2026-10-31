// range: 0x21E5F0 0x21E680
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

extern s32 D_003E09D4;
extern s32 D_003E09D8;
extern s32 D_003E09DC;
extern s32 D_003E09E0;
extern s32 D_003E09E4;
extern s32 D_003E09E8;
extern s32 D_003E09EC;
extern s32 D_003E09F0;
extern char D_003A5D30[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_0021E5F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MsgData msg;

    if (arg0 != 0 && arg3 != 0 && arg2 != 0) {
        D_003E09D4 = arg0;
        D_003E09D8 = arg3;
        D_003E09DC = 0;
        D_003E09E0 = 0;
        D_003E09E4 = 0;
        D_003E09E8 = 0;
        D_003E09F0 = 0;
        D_003E09EC = 0;
        func_00166130(&msg);
        func_00166270(&msg, D_003A5D30);
        func_001661A0(&msg, arg1, arg2);
        func_00166420(&msg);
    }
}
