// range: 0x004682E0 0x00468410
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 field_04;
} BattleGlobal4;

char *func_16D5B0(s32, s32);                          /* extern */
M2C_UNK func_357640(M2C_UNK *, s32, s32);             /* extern */
M2C_UNK func_3577A0(M2C_UNK *, s32, s32);             /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern BattleGlobal4 *D_003E1BB0;

s32 func_004682E0(TagArg *arg0) {
    s32 kind;
    s32 obj;
    char *entry;

    kind = (arg0->tag == 1) ? (s32)*(f32 *)&arg0->bits : arg0->bits;
    obj = D_003E1BB0->field_04;
    switch (kind) {
    case 0:
        func_357640(&D_421AD0, obj, 0);
        entry = func_16D5B0(obj, 0);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        entry = func_16D5B0(obj, 2);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        entry = func_16D5B0(obj, 3);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        break;
    case 1:
        func_3577A0(&D_421AD0, obj, 0);
        entry = func_16D5B0(obj, 0);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        entry = func_16D5B0(obj, 2);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        entry = func_16D5B0(obj, 3);
        if (entry != 0) {
            *(s32 *)(entry + 0x464) = 6;
        }
        break;
    }
    return 1;
}
