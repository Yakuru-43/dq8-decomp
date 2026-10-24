// range: 0x302140 0x3022C0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

typedef struct {
    char pad0[6];
    u8 flags; /* +0x06 */
    char pad7[5];
    s32 id; /* +0x0C */
    char pad10[0x30];
} Slot;

typedef struct {
    u16 group;
    u16 count;
    s32 first;
} Group;

typedef struct {
    char pad0[0x30];
    s32 slotCount; /* +0x30 */
    char pad34[0x14];
    s32 groupCount; /* +0x48 */
} SlotInfo;

typedef struct {
    SlotInfo *info; /* +0x00 */
    Slot *slots;    /* +0x04 */
    char pad8[0xC];
    Group *groups; /* +0x14 */
} SlotTable;

static inline Slot *GetSlot(SlotTable *table, s32 index) {
    if (table->info == 0) {
        return 0;
    }
    if (table->slots == 0) {
        return 0;
    }
    if (table->info->slotCount < 0 || table->info->slotCount <= index) {
        return 0;
    }
    return &table->slots[index];
}

Slot *func_00302140(SlotTable *table, s32 id, s32 bit, s32 *outIndex) {
    s32 group;
    s32 first;
    s32 count;
    s32 i;
    Slot *slots;
    s32 mask;

    if (table->info == 0) {
        return 0;
    }
    group = id / 100;
    count = table->info->slotCount;
    first = 0;
    if (outIndex != 0) {
        *outIndex = 0;
    }
    for (i = 0; i < table->info->groupCount; i++) {
        if (table->groups[i].group == group) {
            first = table->groups[i].first;
            count = table->groups[i].count;
            break;
        }
    }
    slots = GetSlot(table, first);
    mask = 1 << bit;
    for (i = 0; i < count; i++) {
        if (slots[i].id == id && (mask & slots[i].flags)) {
            if (outIndex != 0) {
                *outIndex = first + i;
            }
            return slots;
        }
    }
    return GetSlot(table, 0);
}
