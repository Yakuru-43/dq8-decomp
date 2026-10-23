// range: 0x293560 0x2935AC
#include "common.h"

M2C_UNK func_0028F4F0();                            /* extern */
M2C_UNK func_002AFFB0();                            /* extern */
extern M2C_UNK D_00420C30 __attribute__((section(".data")));   /* extern */
extern M2C_UNK D_004392A0 __attribute__((section(".data")));   /* extern */

struct Record {                                         /* size 0x30 */
    s32 word0;
    s32 rest[11];
};

s32 func_00293560(s32 arg0) {
    struct Record record;

    record.word0 = func_002AFFB0(&D_004392A0,
        *(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x58C) + 0x368) + 0x30));
    return func_0028F4F0(&D_00420C30, &record, 1) >= 1;
}
