// range: 0x47BBA0 0x47BC80
#include "common.h"

typedef struct BattleEntry {
    /* 0x00 */ u8 pad0[0x68];
    /* 0x68 */ s32 count;
    /* 0x6C */ u8 pad6C[0x388 - 0x6C];
    /* 0x388 */ u8 active;
} BattleEntry;

typedef struct BattleParam {
    /* 0x00 */ u8 pad[208];
} BattleParam;

M2C_UNK func_35B720(M2C_UNK *);                        /* extern */
M2C_UNK func_35FA10(s32, M2C_UNK *);                   /* extern */
M2C_UNK func_35F620(M2C_UNK *);                        /* extern */
M2C_UNK func_357870(M2C_UNK *, s32);                   /* extern */
BattleEntry *func_359CF0(M2C_UNK *, s32);               /* extern */
void func_00470CF0(BattleParam *, s32);                 /* extern */
M2C_UNK func_16B3E0(s32, s32, s32, s32);               /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern BattleParam D_452500[] __attribute__((section(".data")));

s32 func_0047BBA0(s32 arg0) {
    BattleEntry *entry;
    s32 i;

    func_35B720(&D_421AD0);
    func_35FA10(arg0, &D_421AD0);
    func_35F620(&D_421AD0);
    func_357870(&D_421AD0, arg0);
    for (i = 0; i < 4; i++) {
        entry = func_359CF0(&D_421AD0, i);
        if (entry != 0) {
            if (entry->count > 0) {
                entry->active = 1;
                func_00470CF0(&D_452500[i], entry->count);
                func_16B3E0(arg0, 1, i, 8);
            }
        }
    }
    return 0;
}
