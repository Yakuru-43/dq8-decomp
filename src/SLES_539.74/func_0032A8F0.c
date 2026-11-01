// range: 0x0032A8F0 0x0032AA40
#include "common.h"

struct Desc {
    char pad0[0xF];
    u8 kind;
    u8 sub;
};

struct Actor {
    char pad0[8];
    u16 state;
    char padA[0x15];
    s8 visible0 : 1;
    s8 bit1 : 1;
    s8 visible2 : 1;
    s8 rest : 5;
    char pad20[0x63];
    u8 ready;
    char pad84[2];
    u8 active;
};

extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

s32 func_0030A890(s32);                                 /* extern */
struct Desc *func_001FFBA0(void *owner, s32 index);     /* extern */

void func_0032A8F0(struct Actor *self, s32 index) {
    s32 id;
    struct Desc *entry;

    if (self->ready != 0) {
        return;
    }
    if (self->active == 0) {
        return;
    }
    id = func_0030A890(index);
    entry = func_001FFBA0(&D_0042CDB0, id);
    switch (id) {
    case 0x60:
    case 0x61:
    case 0x63:
    case 0x64:
    case 0x8B:
    case 0x109:
    case 0x1B6:
    case 0x1B9:
    case 0x78:
        if (self->visible0 != 0 && self->visible2 == 0) {
            self->state = 0xC;
        } else {
            self->state = 0xB;
        }
        break;
    default:
        break;
    }
    if (entry != 0) {
        if (entry->kind == 0x15 && entry->sub == 0x7) {
            self->state = 0x23;
        }
    }
}
