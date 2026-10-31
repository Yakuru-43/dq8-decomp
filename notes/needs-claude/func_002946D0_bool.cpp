// range: 0x2946D0 0x294840
#include "common.h"

extern "C" {

s32 func_002AFFB0(M2C_UNK *tbl, s32 key);           /* extern */
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

typedef struct {
    s32 unk0;
    char pad4[0xC];
    s16 unk10;
    s16 unk12;
    char pad14[0xCC];
    S_Tbl tbl;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
    s32 unk590[6];
    char pad5A8[0x30];
    s32 unk5D8;
    s32 unk5DC;
} S_arg0;

struct Entry {
    s32 word0;
    s32 pad4;
    s32 key;
    u8 unkC;
    u8 unkD;
    char padE[0x26];
};

extern s32 func_00297BA0(S_arg0 *arg0, s32 mode, s32 id, s16 arg3, s32 arg4,
                         s32 count, struct Entry *recs, s64 flag, s64 arg8);

/* ask the stream manager for the two entries of the current mode and hand
   the filled records to func_00297BA0 */
u8 func_002946D0(S_arg0 *arg0) {
    S_Tbl *tbl;
    struct Entry recs[2];
    s32 mode;
    bool flag = true;
    s32 count;
    s32 i;
    s32 word;
    s32 key;
    s32 id;
    s16 arg3;
    s32 arg4;

    tbl = &arg0->unk58C->tbl;
    mode = tbl->unkE0;
    id = arg0->unk58C->unk0;
    arg3 = arg0->unk58C->unk10;
    arg4 = arg0->unk58C->unk12;
    if (tbl->opt != 0 && tbl->opt->unk60 == 0) {
        flag = false;
    }
    count = 0;
    for (i = 0; i < 2; i++) {
        word = func_002AFFB0(&D_004392A0,
                             *(s32 *)(tbl->unk368 + i * 8 + 0x30));
        key = *(s32 *)(tbl->unk368 + i * 8 + 0x34);
        if (key == 0) {
            break;
        }
        recs[i].word0 = word;
        recs[i].key = key;
        recs[i].unkC = 0;
        recs[i].unkD = 0;
        if (mode == 0x17D) {
            recs[i].unkD = 1;
        }
        count++;
    }
    arg0->unk5D8 = 0;
    arg0->unk5DC = 0;
    if (func_00297BA0(arg0, mode, id, arg3, arg4, count, recs, flag, flag) <= 0) {
        return 0;
    }
    return 1;
}

}
