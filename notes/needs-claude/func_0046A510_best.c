// range: 0x46A510 0x46A6D0
#include "common.h"

typedef struct {
    /* 0x00 */ s16 kind;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s32 unk4;
} S_2B14A0; /* size 0x8 */

typedef struct {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 pad1[95];
} S_474770; /* size 0x60 */

typedef struct {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s16 unk4;
} S_351690;

M2C_UNK func_0046DDF0();                                        /* extern */
M2C_UNK func_0046DE00();                                        /* extern */
M2C_UNK func_0046DD10();                                        /* extern */
M2C_UNK func_2B14A0(M2C_UNK, M2C_UNK, void *);                   /* extern */
M2C_UNK func_364100(s32, void *);                                /* extern */
S_351690 *func_351690(s32);                                      /* extern */
M2C_UNK func_374700(s32, s32 *, s32 *);                          /* extern */
M2C_UNK func_2D59A0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_2D59C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_2D5FF0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D58C0(M2C_UNK, M2C_UNK, void *, M2C_UNK);          /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */
s32 func_27BBF0(s32);                                            /* extern */
void func_2D5230(M2C_UNK, s32, s32, s64);                        /* extern */

extern S_474770 D_00474770[] __attribute__((section(".data")));

void func_0046A510(s32 arg0) {
    s32 i;
    M2C_UNK handle;
    S_2B14A0 *e;
    S_474770 *cell;
    S_351690 *entry;
    s32 var_7C;
    s32 var_78;
    S_2B14A0 items[3];

    func_0046DDF0(arg0);
    handle = func_0046DE00();
    func_2B14A0(handle, arg0, items);
    i = 0;
    do {
        cell = &D_00474770[i];
        e = &items[i];
        cell->b0 = 0;
        if (0 < e->kind) {
            func_364100(e->kind, cell);
            entry = func_351690(e->kind);
            if (entry != 0) {
                func_374700(entry->unk4, &var_7C, &var_78);
            }
            func_2D59C0(handle, 0x1F54, i, 1);
            func_2D5FF0(handle, 0x1F54, i, var_7C, var_78);
        } else {
            func_2D59A0(handle, 0x1F54, i, 1);
        }
        func_2D58C0(handle, 0x1F53, cell, i);
        i = i + 1;
    } while (i < 3);
    func_2D58C0(handle, 0x1F53, (void *)func_27BBF0(0x2B), 3);
    func_2D38E0(handle, 0x1F55, 1, -1);
    if (func_0046DD10() == 1) {
        func_2D58C0(handle, 0x1F53, 0, 3);
        func_2D5230(handle, 0x1F69, 0, arg0 + 1);
        func_2D38E0(handle, 0x1F55, 0, -1);
    }
}
