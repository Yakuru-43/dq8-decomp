// range: 0x292A90 0x292C60
// BEST ATTEMPT for func_00292A90 — NOT matched, one word off (+0D4):
//   mine  daddiu $a0, $a0, 1   (flag++ on u64)
//   orig  daddiu $a0, $zero, 1
#include "common.h"

typedef struct S_560 {
    char pad0[0x560];
    u8 unk560;
    u8 unk561;
} S_560;

typedef struct S_Node {
    char pad0[0x1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_560 *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x124];
    u32 unk58C;
    s32 unk590[6];
    s32 unk5A8[6];
    s32 unk5C0[6];
} S_arg0;

extern s32 func_0029CCC0(S_arg0 *arg0, S_Node *node);
extern s32 func_0029CD30(S_arg0 *arg0, S_Node *node);

/* recount from scratch like func_00292960, but a node stays live only while
   its unit is idle: early flags, unit state 1 and a busy unit with the table
   unlocked all put it back to sleep; the two counters track live nodes and
   the third the ones CCC0 or CD30 accepted */
void func_00292A90(S_arg0 *arg0) {
    S_Node *node;
    S_560 *mon;
    s32 table;
    u64 flag;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
        arg0->unk5A8[i] = 0;
        arg0->unk5C0[i] = 0;
    }
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return;
        }
        if (node->unk1 != 0 || node->unk2 != 0) {
            node->unk3 = 0;
            node->unk4 = 0;
            continue;
        }
        mon = node->unk1C;
        if (mon != 0 && mon->unk560 == 1) {
            node->unk3 = 0;
            node->unk4 = 0;
            continue;
        }
        flag = 0;
        if (arg0->unk58C != 0) {
            table = *(s32 *)(arg0->unk58C + 0x368);
            if (table != 0 && (*(u8 *)(table + 4) & 1) != 0) {
                flag++;
            }
        }
        if (mon != 0 && mon->unk561 != 0 && flag == 0) {
            node->unk3 = 0;
            node->unk4 = 0;
            continue;
        }
        if (mon != 0 && mon->unk560 != 0) {
            node->unk3 = 0;
            node->unk4 = 0;
            continue;
        }
        node->unk3 = 1;
        node->unk4 = 1;
        arg0->unk590[node->unk10 >> 8]++;
        arg0->unk5A8[node->unk10 >> 8]++;
        if (func_0029CCC0(arg0, node) != 0 ||
            func_0029CD30(arg0, node) != 0) {
            arg0->unk5C0[node->unk10 >> 8]++;
        }
    }
}
