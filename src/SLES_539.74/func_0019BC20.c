// range: 0x19BC20 0x19BCA0
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

extern s32 D_003E0600;
extern s32 D_003E0604;
extern s32 D_003E0608;
extern char D_003A1A60[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_0019BC20(s32 arg0, s32 arg1, s32 arg2) {
    MsgData msg;

    D_003E0600 = arg0;
    D_003E0604 = 0;
    D_003E0608 = 0;
    if (arg1 != 0) {
        if (arg2 != 0) {
            func_00166130(&msg);
            func_00166270(&msg, D_003A1A60);
            func_001661A0(&msg, arg1, arg2);
            func_00166420(&msg);
        }
    }
}
