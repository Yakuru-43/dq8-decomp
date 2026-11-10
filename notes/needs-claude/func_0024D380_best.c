// range: 0x24D380 0x24D5A0
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02[0x2];
    /* 0x04 */ s32 value04;
    /* 0x08 */ u8 pad_08[0x7];
    /* 0x0F */ s8 kind;
    /* 0x10 */ u8 pad_10[0x1C];
    /* 0x2C */ s32 value2C;
} Entry_003E0B6C; /* size 0x30 */

extern s32 *D_003E0B68;
extern Entry_003E0B6C *D_003E0B6C;
extern f32 D_003DF394;
extern f32 D_003DF73C;

s32 func_0024D380(s32 key, s32 mode, s32 param) {
    Entry_003E0B6C *entry;
    s32 count;
    s32 i;
    s32 val;
    f32 f;
    s32 r;

    if (D_003E0B68 != 0) {
        count = *D_003E0B68;
        entry = D_003E0B6C;
        for (i = 0; i < count; i++, entry++) {
            if (entry->id == key) {
                break;
            }
        }
        entry = 0;
    } else {
        entry = 0;
    }
    if (entry == 0) {
        return 0;
    }
    if (mode != 1) {
        if (mode == 0) {
            return entry->value04;
        }
        return 0;
    }
    val = entry->value2C;
    if (entry->kind == 3) {
        if (param < 50) {
            if (param >= 30) {
                val = val * 300 / 100;
            } else {
                val = val * 100 / 100;
            }
        }
    } else if (entry->kind == 2) {
        if (param >= 2) {
            f = D_003DF394 * (f32)val;
            r = (s32)f;
            if ((f32)r < f) {
                r++;
            }
            val = r;
        } else {
            val = val * 100 / 100;
        }
    } else if (entry->kind == 1) {
        if (param >= 11) {
            f = D_003DF394 * (f32)val;
            r = (s32)f;
            if ((f32)r < f) {
                r++;
            }
            val = r;
        } else if (param >= 6) {
            f = D_003DF73C * (f32)val;
            r = (s32)f;
            if ((f32)r < f) {
                r++;
            }
            val = r;
        }
    }
    return val;
}
