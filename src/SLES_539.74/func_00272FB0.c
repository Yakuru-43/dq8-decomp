// range: 0x272FB0 0x273090
#include "common.h"

extern char D_003C9EF0[];
extern char D_003C9F00[];
extern char D_003C9F30[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern void func_002735F0(void *arg0, u32 *arg1, s32 arg2, u32 *arg3);

typedef union Stamp {
    u32 word;
    u16 half[2];
} Stamp;

typedef struct EntryList {
    u32 field_00;
    u32 count;
    u32 field_08[3];
    u32 *array;
    u32 field_18;
    u32 tailCount;
    u32 *tailArray;
} EntryList;

static inline u32 At(u32 *array, u32 index)
{
    return array[index];
}

void func_00272FB0(EntryList *list, Stamp stamp)
{
    u32 index;
    u32 elem;

    index = stamp.half[0];
    if (!(index < list->count)) {
        func_0012D4D8(D_003C9EF0, 154, D_003C9F30);
    }
    elem = At(list->array, index);
    if (elem != stamp.half[1]) {
        func_0012D4D8(D_003C9EF0, 155, D_003C9F00);
    }
    list->array[index] = 0;
    func_002735F0(&list->field_18, list->tailArray + list->tailCount, 1,
                  &index);
}
