// range: 0x3050A0 0x305160
#include "common.h"

typedef struct {
    char pad0[0x48];
    u16 unk48;
    u16 unk4A;
} S_entry;

typedef struct {
    char pad0[8];
    s16 slots[4];
} S_tbl;

s16 *func_00305240(void *);
S_entry *func_002B0050(void *, s32);
extern M2C_UNK D_004392A0 __attribute__((section(".data")));

s32 func_003050A0(void *obj, s32 count, s32 kind) {
    S_tbl *tbl;
    S_entry *entry;
    s32 idx;
    s32 val;

    if (count <= 0) {
        return 0;
    }
    val = 0;
    tbl = (S_tbl *)func_00305240(obj);
    entry = func_002B0050(&D_004392A0, count);
    if (tbl != 0) {
        if (entry != 0) {
            idx = -1;
            if (kind == entry->unk48) {
                idx = 1;
            } else if (kind == entry->unk4A) {
                idx = 0;
            }
            if (idx >= 0) {
                val = tbl->slots[idx];
                if (val < 999) {
                    val = val + 1;
                }
                tbl->slots[idx] = val;
            }
        }
    }
    return val;
}
