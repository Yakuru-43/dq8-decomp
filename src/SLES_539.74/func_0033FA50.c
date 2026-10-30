// range: 0x33FA50 0x33FAF0
#include "common.h"

void *func_00166130(void *);                          /* extern */
void func_00166270(void *, void *);                   /* extern */
void func_001661A0(void *, void *, s32);              /* extern */
void func_00166420(void *);                           /* extern */
M2C_UNK func_0033F870(M2C_UNK *);                     /* extern */

extern void *D_003E12B8;
extern s32 D_003E12D0;
extern s32 D_003E12D4;
extern M2C_UNK D_004537B0 __attribute__((section(".data")));
extern s32 D_003AE240[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad10[4];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
    s32 unk28;
    void *unk2C;
    s32 unk30;
    void *unk34;
    char pad38[8];
    u8 records[0xE90];
} SaveReader;

s32 func_0033FA50(void *arg0, s32 arg1, void *arg2) {
    SaveReader reader;

    func_00166130(&reader);
    if (arg0 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    D_003E12B8 = arg2;
    D_003E12D0 = 0;
    D_003E12D4 = 0;
    func_0033F870(&D_004537B0);
    func_00166270(&reader, D_003AE240);
    func_001661A0(&reader, arg0, arg1);
    func_00166420(&reader);
    return 1;
}
