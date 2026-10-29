// range: 0x256730 0x2567C0
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
    s8 field_0;
    char pad1[0x8F];
} Entry;

extern s16 D_003E0BF4;
extern Entry *D_003E0BF8;
extern char D_003A72C0[];

void *func_00166130(MsgData *);
s32 func_00166270(MsgData *, char *);
void func_001661A0(MsgData *, s32, s32);
void func_00166420(MsgData *);

void func_00256730(s32 arg0, s32 arg1) {
    MsgData msg;
    Entry *e;
    s32 i;

    D_003E0BF4 = 0;
    e = D_003E0BF8;
    for (i = 0; i < 12; i++) {
        e->field_0 = -1;
        e++;
    }
    func_00166130(&msg);
    func_00166270(&msg, D_003A72C0);
    func_001661A0(&msg, arg0, arg1);
    func_00166420(&msg);
}
