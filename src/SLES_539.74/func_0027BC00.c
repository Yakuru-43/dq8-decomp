// range: 0x27BC00 0x27BCB0
#include "common.h"

struct Entry {
    s16 field0;
    s16 field2;
    s16 field4;
    s16 field6;
    s32 field8;
    s32 fieldC;
    s32 field10;
    s32 field14;
    s32 field18;
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    s32 field2C;
    s32 field30;
    s32 field34;
    s32 field38;
    s32 field3C;
    s32 field40;
    s32 field44;
    s32 field48;
    s32 field4C;
};

struct Pool {
    struct Entry *entries;
    s32 count;
    s32 field8;
};

void *func_0015F490(void);
void func_001419A0(void *, s16, f32);
void func_0027BF50(void *, void *);

void func_0027BC00(struct Pool *pool) {
    struct Entry *entries;
    void *cursor;
    s32 i;

    entries = pool->entries;
    if (entries == 0) {
        return;
    }
    if (pool->count == 0) {
        return;
    }
    if (pool->field8 < 0) {
        return;
    }
    func_001419A0(func_0015F490(), entries->field0, 1.0f);
    cursor = (void *)pool->count;
    i = 0;
    while (i < pool->field8) {
        func_0027BF50(cursor, pool->entries);
        cursor = (void *)((char *)cursor + 0x50);
        i++;
    }
}
