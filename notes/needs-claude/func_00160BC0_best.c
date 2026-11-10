// Best attempt (score 2, reorder-only) for func_00160BC0, 2026-11-02 Qwen factory-1.
// See notes/needs-claude/func_00160BC0.md for the single remaining diff.
// range: 0x160BC0 0x160D50
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 pad02[2];
    s32 field_04;
    s32 field_08;
    u8 pad0C[8];
    s32 field_14;
    s32 field_18;
    u8 pad1C[0x50];
    s32 field_6C;
    u8 pad70[8];
    u8 field_78;
    u8 pad79[3];
} Slot;

extern s32 D_003DFBA8;
extern s32 D_003E02E0;
extern Slot D_003F7900[];
extern Slot D_003F7978[];
M2C_UNK WaitSema(s32);
M2C_UNK SignalSema(s32);
extern s32 func_0011BFB0(s32, void *, s32);

s32 func_00160BC0(s32 id, s32 *out, s32 *out2) {
    s32 val;
    void *buf;
    Slot *p;

    if (id >= 0 && id < 16) {
        p = &D_003F7900[id];
        if (p->field_00 == 0) {
            p = 0;
        } else if (D_003F7978[id].field_00 != 0) {
            p = 0;
        }
    } else {
        p = 0;
    }
    if (p == 0) {
        return -1;
    }
    if (out2 != 0) {
        *out2 = 0;
    }
    switch (p->field_01) {
    case 0:
        if (D_003DFBA8 >= 0) {
            WaitSema(D_003DFBA8);
        }
        D_003E02E0++;
        val = func_0011BFB0(p->field_04, 0, 2);
        buf = (void *)p->field_6C;
        func_0011BFB0(p->field_04, buf, 0);
        if (D_003DFBA8 >= 0) {
            SignalSema(D_003DFBA8);
        }
        D_003E02E0--;
        *out = val;
        break;
    case 2:
        val = p->field_08;
        *out = val;
        break;
    case 4:
    case 1:
        *out = p->field_18;
        val = p->field_08;
        if (out2 != 0) {
            *out2 = p->field_14;
        }
        if (p->field_14 == 0) {
            *out = p->field_08;
        }
        break;
    default:
        val = -1;
        break;
    }
    return val;
}
