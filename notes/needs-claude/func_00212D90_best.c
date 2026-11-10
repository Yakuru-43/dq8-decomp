// range: 0x212D90 0x212F10
#include "common.h"

s32 func_0015F490(void);                            /* extern */
s32 func_0015F450(void);                            /* extern */
s32 func_0015AEF0(s32, void *, s32);                 /* extern */
void func_001419A0(s32, s32, f32);                   /* extern */
s32 func_00141BF0(s32);                             /* extern */
void func_002112C0(s32);                            /* extern */
void func_0013E2F0(s32, s32);                       /* extern */
s32 func_00133F78(s32, s32);                        /* extern */
void func_0022B020(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_00141B00(s32);                             /* extern */
extern char *D_003E093C;
extern s16 D_003E0938;
extern char D_003C7CD0[];
extern char D_003A54C0[];

void func_00212D90(s32 arg0, s32 arg1) {
    s32 handle;
    s32 found;
    s32 obj;
    s32 i;
    char *entry;
    char *tab;
    s32 kind;

    if (D_003E0938 <= 0) {
        return;
    }
    func_0015F490();
    handle = func_0015F450();
    found = func_0015AEF0(handle, &D_003C7CD0, -1);
    if (found == 0) {
        return;
    }
    func_001419A0(handle, *(s16 *)found, 1.0f);
    obj = func_00141BF0(handle);
    func_002112C0(obj);
    func_0013E2F0(obj, 1);
    for (i = 0; i < D_003E0938; i++) {
        entry = D_003E093C + i * 44;
        if (func_00133F78((s32)entry, arg0) == 0) {
            kind = M2C_FIELD(entry, s32 *, 0x20);
            tab = D_003A54C0 + kind * 12;
            func_0022B020(obj, found,
                          M2C_FIELD(entry, s32 *, 0x24), M2C_FIELD(entry, s32 *, 0x28),
                          M2C_FIELD(tab, s16 *, 8), M2C_FIELD(tab, s16 *, 0xA),
                          M2C_FIELD(tab, s16 *, 0), M2C_FIELD(tab, s16 *, 2),
                          M2C_FIELD(tab, s16 *, 4), M2C_FIELD(tab, s16 *, 6),
                          0x80, arg1);
        }
    }
    func_00141B00(handle);
}
