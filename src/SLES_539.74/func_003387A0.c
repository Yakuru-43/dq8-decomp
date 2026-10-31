// range: 0x3387A0 0x338850
#include "common.h"

void *func_00166130(void *);                          /* extern */
void func_00166270(void *, void *);                   /* extern */
void func_001661A0(void *, void *, s32);              /* extern */
void func_00166420(void *);                           /* extern */
void func_003244A0(void);                             /* extern */
void func_003244B0(void);                             /* extern */

extern void *D_003E1248;
extern s32 D_003E124C;
extern s32 D_003E1250;
extern s32 D_003E1254;
extern s8 D_004534A0 __attribute__((section(".data")));
extern s32 D_003AE130[];

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

s32 func_003387A0(void *arg0, s32 arg1, void *arg2) {
    SaveReader reader;

    if (arg0 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    func_00166130(&reader);
    D_003E1248 = arg2;
    D_004534A0 = 0;
    D_003E124C = 0;
    D_003E1250 = 0;
    D_003E1254 = 0;
    func_003244B0();
    func_00166270(&reader, D_003AE130);
    func_001661A0(&reader, arg0, arg1);
    func_00166420(&reader);
    func_003244A0();
    return 1;
}
