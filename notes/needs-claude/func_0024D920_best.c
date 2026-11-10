// best attempt for func_0024D920 (CLASS structural score=24, 176 vs 168 B)
// range: 0x24D920 0x24D9D0
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02[2];
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08[2];
} Entry_003E0B5C; /* size 0x10 */

extern s16 D_003E0B58;
extern Entry_003E0B5C *D_003E0B5C;
void func_001340C0(u8 *, u32);

s32 func_0024D920(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    Entry_003E0B5C *entry;
    u32 value;
    s16 count;
    s32 i;

    *arg2 = 0;
    entry = D_003E0B5C;
    if (entry == 0) {
        return 0;
    }
    count = D_003E0B58;
    i = 0;
    while (i < count) {
        if (entry->id == arg0) {
            if (arg1 == 0) {
                value = entry->unk04;
                if (value != 0) {
                    func_001340C0(arg2, value);
                    return 1;
                }
            }
            if (arg1 != 1) {
                return 0;
            }
            value = entry->unk08[arg3];
            if (value == 0) {
                return 0;
            }
            func_001340C0(arg2, value);
            return 1;
        }
        i++;
        entry++;
    }
    return 0;
}
