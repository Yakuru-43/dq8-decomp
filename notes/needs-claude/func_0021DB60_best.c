// range: 0x21DB60 0x21DC80
// best draft, session 2026-11-01 factory-2 (score 59; see func_0021DB60.md)
#include "common.h"

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ f32 field_0C;
    /* 0x10 */ f32 field_10;
    /* 0x14 */ f32 field_14;
    /* 0x18 */ f32 field_18;
    /* 0x1C */ f32 field_1C;
    /* 0x20 */ f32 field_20;
} SortEntry;

typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ SortEntry *entries;
} SortList;

extern SortList *D_003E09E0;

s32 func_0021DB60(void) {
    SortEntry *entries;
    s32 count;
    s32 i;
    s32 j;
    SortList *list = D_003E09E0;

    if (list == 0) {
        return 0;
    }
    count = list->count;
    entries = list->entries;
    for (i = 0; i < count - 1; i++) {
        SortEntry *a = &entries[i];
        for (j = i + 1; j < count; j++) {
            SortEntry *b = &entries[j];
            f32 *bk = &b->field_14;
            if (a->field_14 > b->field_14) {
                s32 w0 = a->field_00;
                s32 w1 = a->field_04;
                s32 w2 = a->field_08;
                f32 x0 = a->field_0C;
                f32 x1 = a->field_10;
                f32 x2 = a->field_14;
                f32 x3 = a->field_18;
                f32 x4 = a->field_1C;
                f32 x5 = a->field_20;
                a->field_00 = b->field_00;
                a->field_04 = b->field_04;
                a->field_08 = b->field_08;
                a->field_0C = b->field_0C;
                a->field_10 = b->field_10;
                a->field_14 = b->field_14;
                a->field_18 = b->field_18;
                a->field_1C = b->field_1C;
                a->field_20 = b->field_20;
                b->field_00 = w0;
                b->field_04 = w1;
                b->field_08 = w2;
                b->field_0C = x0;
                b->field_10 = x1;
                *bk = x2;
                b->field_18 = x3;
                b->field_1C = x4;
                b->field_20 = x5;
            }
        }
    }
    return 1;
}
