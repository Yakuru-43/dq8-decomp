// range: 0x47BEA0 0x47BF70
#include "common.h"

extern "C" {

typedef struct BattleEntry {
    /* 0x00 */ s32 tag;
    /* 0x04 */ u8 pad04[0x388 - 0x04];
    /* 0x388 */ u8 active;
} BattleEntry;

typedef struct SearchResult {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ s32 field4;
} SearchResult;

typedef struct TagPair {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 kind;
} TagPair;

BattleEntry *func_359CF0(M2C_UNK *, s32);               /* extern */
char *func_16D5B0(s32, s32);                           /* extern */
SearchResult *func_2B02C0(M2C_UNK *, s32);             /* extern */
M2C_UNK func_2C7140(s32, s32);                         /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern M2C_UNK D_42EAA0 __attribute__((section(".data")));

s32 func_0047BEA0(s32 arg0, TagPair *a1, M2C_UNK *arg2) {
    s32 kind;
    BattleEntry *entry;
    SearchResult *result;
    char *r;

    kind = a1->kind;
    entry = func_359CF0(&D_421AD0, kind);
    r = func_16D5B0(arg0, kind);
    result = 0;
    if (entry == 0 || r == 0) {
        return 1;
    }
    entry->active = 0;
    if (kind >= 5) {
        if (kind < 0xA0) {
            if (entry != 0) {
                result = func_2B02C0(&D_42EAA0, entry->tag);
            }
            if (result != 0) {
                if (result->field4 != 0) {
                    func_2C7140(arg0, kind);
                }
            }
        }
    }
    return 0;
}

}
