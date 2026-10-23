// range: 0x211FF0 0x212080
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

extern u8 *D_003E0928;
extern void *D_003E0950;
extern char D_003A58A0[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_00211FF0(s32 arg0, s32 arg1) {
    MsgData msg;
    s32 i;

    if (arg0 == 0) {
        return;
    }
    D_003E0950 = NULL;
    for (i = 0; i < 32; i++) {
        D_003E0928[i * 0xA0 + 4] = 0;
    }
    func_00166130(&msg);
    func_00166270(&msg, D_003A58A0);
    func_001661A0(&msg, arg0, arg1);
    func_00166420(&msg);
}
