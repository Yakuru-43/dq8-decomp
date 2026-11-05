// range: 0x4756F0 0x475790
#include "common.h"

M2C_UNK func_131188(char *, M2C_UNK, M2C_UNK);      /* extern */

typedef struct Entry {
    s32 unk0;                                        /* 0x00 */
    u8 pad04[0x30];                                  /* 0x04 */
    char pad34[0x20];                                /* 0x34 */
    struct Entry *unk54;                             /* 0x54 */
    struct Entry *unk58;                             /* 0x58 */
} Entry;

typedef struct {
    u8 pad0[0x84];                                   /* 0x00 */
    Entry *unk84;                                    /* 0x84 */
    Entry *unk88;                                    /* 0x88 */
} Table;

void func_004756F0(Table *table, Entry *entry) {
    Entry *prev = entry->unk54;
    Entry *next = entry->unk58;

    if (prev != 0) {
        prev->unk58 = next;
    }
    if (next != 0) {
        next->unk54 = prev;
    }
    if (prev == 0) {
        if (next == 0) {
            table->unk84 = 0;
            table->unk88 = 0;
        }
    }
    if (prev == 0) {
        if (next != 0) {
            table->unk88 = next;
        }
    }
    if (prev != 0) {
        if (next == 0) {
            table->unk84 = prev;
        }
    }
    entry->unk0 = 0;
    entry->unk54 = 0;
    entry->unk58 = 0;
    func_131188(entry->pad34, 0, 0x20);
}
