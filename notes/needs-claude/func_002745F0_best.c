// range: 0x2745F0 0x274730
#include "common.h"

typedef union Stamp {
    u32 word;
    u16 half[2];
} Stamp;

typedef struct StampList {
    u32 field_00;
    u32 count;
    u8 *records;
    u32 field_0C;
    u32 tailCount;
    u32 *tailArray;
    u32 field_18;
    u32 stampCount;
    u32 *stampArray;
} StampList;

extern void func_002747F0(Stamp *stamp, u32 value);
extern void func_00274A30(StampList *list, u8 *record, s32 count, u32 *out);
extern void func_002735F0(void *arg0, u32 *arg1, s32 arg2, u32 *arg3);
extern void func_001007A0(void *node);

static inline u32 At(u32 *array, u32 index)
{
    return array[index];
}

u8 *func_002745F0(StampList *list, Stamp *stamp)
{
    u32 index;
    u32 buf[4];
    u32 *flags;
    u32 value;
    u32 i;

    if (list->stampCount != 0) {
        index = At(list->stampArray, list->stampCount - 1);
        func_002747F0(stamp, index);
        list->stampCount = list->stampCount - 1;
        list->tailArray[index] = stamp->half[1];
    } else {
        index = list->tailCount;
        func_002747F0(stamp, index);
        flags = buf + 1;
        for (i = 0; i < 3; i++) {
            flags[i] = 0;
        }
        func_00274A30(list, list->records + (list->count << 4), 1, buf);
        if (flags != 0 && (*flags & 1)) {
            func_001007A0((void *)buf[3]);
        }
        value = stamp->half[1];
        func_002735F0(&list->field_0C, list->tailArray + list->tailCount, 1,
                      &value);
    }
    return list->records + (index << 4);
}
