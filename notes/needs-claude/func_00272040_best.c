// range: 0x272040 0x272120 — best attempt, score 8 (reorder+register), NOT matched
#include "common.h"

/* file name + the two failed expressions */
extern char D_003C9EF0[];
extern char D_003C9F00[];
extern char D_003C9F30[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern void func_002735F0(void *list, void *entry, u32 count, void *idx);

typedef struct Table {
    u32 field_00;
    u32 count;      /* 0x04 */
    u32 field_08[3];
    u32 *entries;   /* 0x14 */
    u32 field_18;   /* 0x18 */
    u32 field_1C;   /* 0x1C */
    u32 *base_20;   /* 0x20 */
} Table;

typedef struct Selection {
    u16 idx;
    u16 tag;
} Selection;

void func_00272040(Table *table, Selection selection)
{
    u32 idx = selection.idx;

    if (!(idx < table->count)) {
        func_0012D4D8(D_003C9EF0, 154, D_003C9F30);
    }
    if (table->entries[idx] != selection.tag) {
        func_0012D4D8(D_003C9EF0, 155, D_003C9F00);
    }
    table->entries[idx] = 0;
    func_002735F0(&table->field_18, table->base_20 + table->field_1C, 1,
                  &idx);
}
