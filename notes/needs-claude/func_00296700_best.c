// best attempt, not committed to src/ — did not match
// range: 0x296700 0x296850
#include "common.h"

typedef struct S_560 {
    char pad0[0x10];
    s16 unk10;
    s16 unk12;
} S_560;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    char pad4[0xC];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_560 *unk1C;
} S_Node;

typedef struct {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
} S_Result;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x124];
    S_Result *unk58C;
    s32 unk590[6];
} S_arg0;

extern void func_00292960(S_arg0 *arg0);
extern s32 func_002915F0(S_arg0 *arg0, u8 arg1);
extern s32 func_00132D38(void);
extern s32 func_00296850(S_arg0 *arg0);

/* roll 1..100 and spend it over the weight row of the wanted kind, then
   walk the running nodes for the i-th live one and copy its item pair out */
s32 func_00296700(S_arg0 *arg0) {
    S_Result *result;
    S_Node *node;
    s32 count;
    s32 off;
    s32 remain;
    s32 i;
    s32 w;

    result = (S_Result *)((char *)arg0->unk58C + 0xE0);
    func_00292960(arg0);
    count = func_002915F0(arg0, 0);
    if (count <= 0) {
        return 0;
    }
    remain = func_00132D38() % 100 + 1;
    off = (count - 1) * 5;
    for (i = 0; i < 5; i++) {
        w = *(u8 *)(off + i + func_00296850(arg0) + 0xFA);
        if (w >= remain) {
            break;
        }
        remain -= w;
    }
    if (count - 1 < i) {
        i = count - 1;
    }
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return 0;
        }
        if (node->unk3 == 0) {
            continue;
        }
        if (i != 0) {
            i--;
            continue;
        }
        result->unk10 = node->unk1C->unk10;
        result->unk14 = node->unk1C->unk12;
        return 1;
    }
    return node->unk10;
}
