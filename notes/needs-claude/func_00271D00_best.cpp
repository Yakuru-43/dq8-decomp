// range: 0x271D00 0x271D80
// Look up record `index` of a stamped list: the stamp's low half is the
// index, its high half must match the list's stamp slot.
#include "common.h"

typedef union Stamp {
    u32 word;
    u16 half[2];
} Stamp;

typedef struct StampList {
    u32 field_00;
    u32 count;
    char *records;
    u32 field_0C[2];
    u32 *stamps;
} StampList;

extern "C" {

static inline u32 At(u32 *array, u32 index) {
    return array[index];
}

void *func_00271D00(StampList *list, Stamp stamp) {
    Stamp key;
    u32 index;
    void *res;

    key = stamp;
    if ((key.word == 0) != false) {
        res = 0;
    } else {
        index = key.half[0];
        if (index < list->count && key.half[1] == At(list->stamps, index)) {
            res = list->records + index * 16;
        } else {
            res = 0;
        }
    }
    return res;
}

}
