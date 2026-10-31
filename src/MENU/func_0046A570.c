// range: 0x46A570 0x46A600
#include "common.h"

struct Entry {
    char pad[0x12];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
};

M2C_UNK func_22AB50(M2C_UNK);                          /* extern */
s32 func_0046AA70(void);                               /* extern */
void func_0046A7A0(s32);                               /* extern */
s8 func_388BA0(s8);                                    /* extern */
void func_311F30(s32, s8);                             /* extern */
void func_37C920(void);                                /* extern */
s32 func_201CD0();                                     /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK D_00479360 __attribute__((section(".data")));

s32 func_0046A570(struct Menu *menu) {
    s16 h;
    s32 a;
    s8 b;

    func_22AB50(0);
    h = menu->f18->f12;
    a = func_0046AA70();
    b = func_388BA0((s8)h);
    func_311F30(a, b);
    func_37C920();
    func_0046A7A0(0);
    func_370C00(func_201CD0(), &D_00479360, 0);
    return 1;
}
