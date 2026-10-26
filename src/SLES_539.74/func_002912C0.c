// range: 0x2912C0 0x291400
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: cf. func_00301200.c)
#include "common.h"

struct Record {
    char pad[0x10];
    s16 val10;
    s16 val12;
};

struct Entry {
    char pad[0x10];
    s32 state;
    s32 sub;
};

struct Node {
    char pad0[0x3];
    u8 unk3;
    char pad4[0xC];
    u16 unk10;
    char pad12[0x6];
    struct Node *unk18;
    struct Record *unk1C;
};

struct Owner {
    char pad[0x448];
    struct Node head;
    char pad468[0x124];
    u32 table;
};

M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern s32 func_002915F0(struct Owner *owner, u8 kind);
extern s32 func_00132D38(void);
extern M2C_UNK D_003CB108 __attribute__((section(".data")));

/* pick the rem-th still-running node of the table and copy the two record
   values into the entry past +0xE0; a node without a record falls back to
   the table's own values */
void func_002912C0(struct Owner *owner) {
    struct Entry *entry = (struct Entry *)(owner->table + 0xE0);
    s32 count;
    s32 rem;
    s32 i;
    struct Node *node;

    count = func_002915F0(owner, 0);
    func_00300CB0(0 < count, &D_003CB108, 0x1BAF);
    if (count == 0) {
        func_00300CB0(0, &D_003CB108, 0x1BB4);
        entry->state = ((struct Record *)owner->table)->val10;
        entry->sub = ((struct Record *)owner->table)->val12;
        return;
    }
    rem = func_00132D38() % count;
    i = 0;
    node = &owner->head;
    while (node->unk18 != 0) {
        node = node->unk18;
        if (node->unk10 == 0xFFFF) {
            break;
        }
        if (node->unk3 != 0) {
            if (i++ == rem) {
                break;
            }
        }
    }
    if (node->unk1C != 0) {
        entry->state = node->unk1C->val10;
        entry->sub = node->unk1C->val12;
    } else {
        func_00300CB0(0, &D_003CB108, 0x1BCE);
        entry->state = ((struct Record *)owner->table)->val10;
        entry->sub = ((struct Record *)owner->table)->val12;
    }
}
