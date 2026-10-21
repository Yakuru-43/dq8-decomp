// range: 0x292C60 0x292CB0
#include "common.h"

struct Owner {
    char pad[0x58C];
    u32 table;
};

struct Table {
    char pad[0x10];
    s16 kind;
    char pad2[0xD6];
    s32 mode;
};

/* 1 while the selected table is running normally, inverted in mode 3 */
s32 func_00292C60(struct Owner *owner) {
    struct Table *table = (struct Table *)owner->table;
    s32 ret;

    if (table->kind == 0 || table->kind == 1) {
        ret = 0;
    } else {
        ret = 1;
    }
    if (table->mode == 3) {
        ret ^= 1;
    }
    return ret;
}
