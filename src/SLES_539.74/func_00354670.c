// range: 0x354670 0x3548E0
#include "common.h"

s32 func_0012D4C0(s32);
void CPutMonster_Insert(char *, char *, s32);

union Vec4_354670 {
    /* 0x00 */ u128 q;
    /* 0x00 */ struct { f32 x, y, z, w; } v;
};

struct Slot354670 {
    /* 0x00 */ s32 type;
    /* 0x10 */ union Vec4_354670 vec;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 key;
    /* 0x28 */ s32 unk28;
};

static inline s32 FindSlot354670(char *base, s32 key) {
    s32 i;

    if (key < 0) {
        return -1;
    }
    for (i = 0; i < 0x20; i++) {
        if (*(s32 *)(base + i * 0x30 + 0x24) == key) {
            return i;
        }
    }
    return -1;
}

void func_00354670(char *arg0, char *arg1) {
    struct Slot354670 *slot;
    struct Slot354670 *next;
    s32 firstActive;
    s32 lastActive;
    s32 found20;
    s32 idx;
    s32 j;
    s32 distA;
    s32 distB;

    if (arg1 == 0) {
        return;
    }
    lastActive = 1;
    idx = FindSlot354670(arg0, *(s16 *)(arg1 + 0xC));
    if (idx >= 0) {
        slot = (struct Slot354670 *)(arg0 + idx * 0x30);
        slot->type = 0;
        slot->unk20 = -1;
        slot->key = -1;
        slot->unk28 = -1;
        slot->vec.q = 0;
        while (idx < 0x1F) {
            next = (struct Slot354670 *)(arg0 + (idx + 1) * 0x30);
            slot = (struct Slot354670 *)(arg0 + idx * 0x30);
            idx++;
            slot->type = next->type;
            slot->vec.v = next->vec.v;
            slot->unk20 = next->unk20;
            slot->key = next->key;
            slot->unk28 = next->unk28;
        }
        slot = (struct Slot354670 *)(arg0 + 0x5D0);
        slot->type = 0;
        slot->unk20 = -1;
        slot->key = -1;
        slot->unk28 = -1;
        slot->vec.q = 0;
    }
    firstActive = 0;
    while (firstActive < 0x20) {
        if (*(s32 *)(arg0 + firstActive * 0x30) == 1) {
            break;
        }
        firstActive++;
    }
    if (firstActive == 0x20) {
        firstActive = 0;
    }
    for (j = 0; j < 0x20; j++) {
        if (*(s32 *)(arg0 + j * 0x30) == 1) {
            lastActive = j;
        }
    }
    found20 = 0;
    while (found20 < 0x20) {
        if (*(s32 *)(arg0 + 0x604) == *(s32 *)(arg0 + found20 * 0x30 + 0x20)) {
            break;
        }
        found20++;
    }
    if (found20 == 0x20) {
        found20 = 0;
    }
    distA = func_0012D4C0(found20 - firstActive);
    distB = func_0012D4C0(lastActive - found20);
    if (distA < distB) {
        CPutMonster_Insert(arg0, arg1, firstActive);
    } else {
        CPutMonster_Insert(arg0, arg1, lastActive + 1);
    }
}
