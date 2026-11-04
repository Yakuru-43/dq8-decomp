// best attempt for func_00371630 (2026-11-04 factory-3, CLASS structural score=71)
// range: 0x371630 0x371780
#include "common.h"

typedef struct Node {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 pad_01[1];
    /* 0x02 */ s16 id;
    /* 0x04 */ char pad_04[4];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 speed;
    /* 0x10 */ char pad_10[0x14];
    /* 0x24 */ char name[1];
    /* 0x25 */ char pad_25[0x3F];
    /* 0x64 */ s16 unk_64;
} Node; /* size 0x68 */

typedef struct Info {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 pad_01[3];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char name[0x40];
} Info; /* size 0x54 */

void func_0025B640(s32, s32 *);
s32 func_0025B760(s32);
s32 func_0025AB80(s32);
char *func_001340C0(char *, char *);

s32 func_00371630(Node **list, s32 index) {
    s32 results[4];
    Info info;
    s32 *res;
    Node *node;
    s32 code;
    s32 diff;

    if (index < 0 || index >= 6) {
        node = 0;
    } else {
        node = list[index];
    }
    if (node == 0) {
        return 0xB4;
    }
    if (node->active == 0) {
        return 0xB4;
    }
    if (node->unk_64 == 0) {
        code = -2;
    } else if (node->unk_64 < 0) {
        code = func_0025B760(node->id);
    } else {
        code = -1;
    }
    if (code == 1) {
        res = results;
        func_0025B640(node->id, res);
        info.unk_00 = 0;
        if (res[0] > 0) {
            info.unk_00 = 1;
        }
        info.unk_04 = node->unk_08;
        info.unk_08 = node->speed;
        info.unk_0C = func_0025B760(node->id);
        info.unk_10 = func_0025AB80(node->id);
        func_001340C0(info.name, node->name);
        diff = (s32)(node->speed * (f32)res[0]) - res[1];
        return (s32)(30.0f * (f32)diff / 57344.0f);
    }
    return 0x708;
}
