// CLASS structural score=2 (2 words differ, 316 vs 316 bytes)
// best C for func_00294980 (320 bytes) — identical output for found as s32/u64/1LL
// range: 0x294980 0x294ABC
#include "common.h"

extern M2C_UNK D_00421410 __attribute__((section(".data")));

M2C_UNK func_002914D0();                          /* extern */
s32 func_0029CD30();                              /* extern */
s32 func_0029CCC0();                              /* extern */
s32 func_00302850();                              /* extern */
s32 func_00292C60();                              /* extern */

typedef struct {
    char pad0[0x60];
    s16 unk60;
} S_Counted;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_Counted *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x124];
    u32 table;
} S_arg0;

s32 func_00294980(S_arg0 *arg0) {
    s32 running;
    s32 maxv;
    S_Node *node;
    s32 found;
    s32 value;
    s32 limit;
    s32 count;

    count = func_00302850(&D_00421410);
    limit = ((S_Counted *)arg0->table)->unk60;
    if (count < limit) {
        limit = count;
    }
    maxv = 0;
    running = func_00292C60(arg0);
    for (node = &arg0->head; (node = node->unk18) != NULL;) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        if (node->unk3 == 0) {
            continue;
        }
        found = 0;
        value = 0;
        if (running == 0) {
            if (func_0029CD30(arg0, node) != 0) {
                value = node->unk1C->unk60;
                found = 1;
            }
        } else {
            if (func_0029CCC0(arg0, node) != 0) {
                value = node->unk1C->unk60;
                found = 1;
            }
        }
        if (found != 0) {
            if (maxv < value) {
                maxv = value;
            }
        }
    }
    if (maxv - limit >= 6) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
