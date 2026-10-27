// range: 0x2937C0 0x293A30
#include "common.h"

M2C_UNK func_002AFFB0();                            /* extern */
extern M2C_UNK D_004392A0 __attribute__((section(".data")));   /* extern */

typedef struct S_Opt {
    char pad0[0x60];
    u8 unk60;
} S_Opt;

typedef struct S_Tbl {
    s32 unkE0;
    char padE4[0x280];
    S_Opt *opt;
    s32 unk368;
} S_Tbl;

typedef struct S_58C {
    s32 unk0;
    char pad4[0xC];
    s16 unk10;
    s16 unk12;
    char pad14[0xCC];
    S_Tbl tbl;
} S_58C;

typedef struct S_Node {
    char pad0[3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[4];
    struct S_Node *unk18;
    s32 *unk1C;
} S_Node;

typedef struct S_arg0 {
    char pad0[0x448];
    S_Node head;
    char pad468[0x124];
    S_58C *unk58C;
    char pad590[0x48];
    s32 unk5D8;
    s32 unk5DC;
} S_arg0;

struct Entry {
    s32 word0;
    s32 field4;
    s32 key;
    u8 unkC;
    u8 unkD;
    char padE[2];
    s32 cnt10;
    char pad14[0x20];
};

extern s32 func_00297BA0(S_arg0 *arg0, s32 mode, s32 id, s32 arg3, s32 arg4,
                         s32 count, struct Entry *recs, s64 flag, s64 arg8);
extern s32 func_00292C60(S_arg0 *arg0);
extern u8 func_0029CCC0(S_arg0 *arg0, S_Node *node);
extern u8 func_0029CD30(S_arg0 *arg0, S_Node *node);

/* build the records for the two current table entries, hand them to the
   resource loader and cancel every queued unit that still points at one */
s32 func_002937C0(S_arg0 *arg0) {
    S_Tbl *tbl;
    struct Entry recs[2];
    s64 flag;
    s32 count;
    u32 sum;
    s32 i;
    s32 mode;
    s32 id;
    s32 arg3;
    s32 arg4;
    s32 word;
    s32 key;
    s32 res;
    s32 ret;
    S_Node *node;
    s32 target;
    s32 k;

    tbl = &arg0->unk58C->tbl;
    flag = 1;
    if (tbl->opt != 0 && tbl->opt->unk60 == 0) {
        flag = 0;
    }
    mode = arg0->unk58C->tbl.unkE0;
    arg3 = arg0->unk58C->unk10;
    arg4 = arg0->unk58C->unk12;
    id = arg0->unk58C->unk0;
    count = 0;
    sum = 0;
    for (i = 0; i < 2; i++) {
        word = func_002AFFB0(&D_004392A0,
                             *(s32 *)(tbl->unk368 + i * 8 + 0x30));
        key = *(s32 *)(tbl->unk368 + i * 8 + 0x34);
        if (key == 0) {
            break;
        }
        count++;
        sum += key;
        recs[i].word0 = word;
        recs[i].field4 = -1;
        recs[i].key = key;
        recs[i].unkC = 0;
        recs[i].unkD = 0;
    }
    arg0->unk5D8 = 0;
    arg0->unk5DC = 0;
    ret = func_00297BA0(arg0, mode, id, arg3, arg4, count, recs, flag, flag);
    if (arg0->unk5D8 <= 0 || arg0->unk5DC != arg0->unk5D8) {
        return 0;
    }
    res = func_00292C60(arg0);
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        node->unk4 = node->unk3;
        if (node->unk3 == 0) {
            continue;
        }
        if (res == 0) {
            if (func_0029CCC0(arg0, node) == 0) {
                continue;
            }
        } else if (func_0029CD30(arg0, node) == 0) {
            continue;
        }
        target = *node->unk1C;
        for (k = 0; k < count; k++) {
            if (recs[k].word0 == target) {
                ret--;
                recs[k].cnt10 -= 1;
                if (ret == 0) {
                    break;
                }
            }
        }
        if (ret == 0) {
            break;
        }
    }
    return (ret == sum);
}
