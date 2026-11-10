// range: 0x2934D0 0x293560
#include "common.h"

M2C_UNK func_0028F4F0();                            /* extern */
M2C_UNK func_00292960();                            /* extern */
extern M2C_UNK D_00420C30 __attribute__((section(".data")));   /* extern */

struct Record {                                         /* size 0x30 */
    s32 word0;
    s32 rest[11];
};

s32 func_002934D0(s32 arg0) {
    s32 saved;
    struct Record record;

    saved = *(s32 *)(*(s32 *)(arg0 + 0x58C) + 0xE8);
    *(s32 *)(*(s32 *)(arg0 + 0x58C) + 0xE8) = 2;
    func_00292960();
    *(s32 *)(*(s32 *)(arg0 + 0x58C) + 0xE8) = saved;
    if (*((s32 *)(*(s16 *)(*(s32 *)(arg0 + 0x58C) + 0x10) * 4 + arg0) + 0x164) == 8) {
        record.word0 = *(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x58C) + 0x368) + 0x30);
        return func_0028F4F0(&D_00420C30, &record, 1) >= 1;
    } else {
        return 0;
    }
}
