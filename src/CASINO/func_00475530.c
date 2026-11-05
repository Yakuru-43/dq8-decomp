// range: 0x475530 0x475620
#include "common.h"

typedef struct {                              /* table sub-object, size 0x10 */
    u8 unk0[0xC];
    f32 unkC;
} Pair;

typedef struct {
    u8 pad0[0x10];                            /* 0x00 */
    u8 unk10[0x10];                           /* 0x10 */
    u8 unk20[0x10];                           /* 0x20 */
    Pair unk30;                               /* 0x30 */
    Pair unk40;                               /* 0x40 */
    u8 pad50[0xC94 - 0x50];                   /* 0x50 */
    s32 unkC94;                               /* 0xC94 */
} Table;

typedef struct {
    u8 pad0[0x10];                            /* 0x00 */
    u8 unk10[0x10];                           /* 0x10 */
    u8 unk20[0x10];                           /* 0x20 */
    s32 unk30;                                /* 0x30 */
    s32 unk34;                                /* 0x34 */
    s32 unk38;                                /* 0x38 */
} Entry;

M2C_UNK func_13B7B0(void *, void *, void *);
M2C_UNK func_13B7D0(void *, void *, void *);
M2C_UNK func_10AD00(void *, void *, f32);

s32 func_00475530(Table *table, Entry *entry) {
    if (table->unkC94 != 0) {
        return 2;
    }
    if (entry->unk38 > entry->unk34) {
        entry->unk30 = -1;
        return 2;
    }
    if (entry->unk38 <= 0) {
        func_13B7D0(&table->unk30, entry->unk10, table->unk10);
        func_10AD00(&table->unk30, &table->unk30, (f32) entry->unk34);
        table->unk30.unkC = 1.0f;
        func_13B7D0(&table->unk40, entry->unk20, table->unk20);
        func_10AD00(&table->unk40, &table->unk40, (f32) entry->unk34);
        table->unk40.unkC = 1.0f;
    }
    func_13B7B0(table->unk10, table->unk10, &table->unk30);
    func_13B7B0(table->unk20, table->unk20, &table->unk40);
    entry->unk38 += 1;
    return 3;
}
