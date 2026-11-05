// range: 0x46E2C0 0x46E360
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
    char pad1[6];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
    char pad2[4];
    void *f20;
};

extern s32 func_202530(void);                                                /* extern */
M2C_UNK func_2D38E0(s32, s32, s32, s32);                                    /* extern */
M2C_UNK func_370590(void *, s32);                                           /* extern */
extern int func_37AB80();                                                    /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                                               /* extern */
M2C_UNK func_37CE30(M2C_UNK);                                               /* extern */

s32 func_0046E2C0(struct Menu *menu, s32 arg1) {
    menu->f18->fA = func_202530() - 1;
    func_2D38E0(arg1, 0x18703, 1, -1);
    func_370590(menu->f20, 0x28);
    func_37AB80(1, menu->f18->f12, 1);
    func_37CEE0(1);
    func_37CE30(1);
    func_2D38E0(arg1, 0x4B3, 0, -1);
    return 1;
}
