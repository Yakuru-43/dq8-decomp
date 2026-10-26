// range: 0x292CD0 0x292E00
#include "common.h"

M2C_UNK func_002AFFB0();
M2C_UNK func_00359440();
extern M2C_UNK D_004392A0 __attribute__((section(".data")));
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

/* three resources of the unit are held: ask the stream manager for each of
   the ids behind the table entries, all three must report more than zero */
s32 func_00292CD0(s32 arg0) {
    s32 base;
    s32 key0;
    s32 key1;
    s32 key2;
    s32 key3;
    s32 id0;
    s32 id1;
    s32 id2;
    s32 n1;
    s32 n2;
    s32 n3;

    base = *(s32 *)(*(s32 *)(arg0 + 0x58C) + 0x368);
    key0 = *(s32 *)(base + 0x30);
    key1 = *(s32 *)(base + 0x34);
    key2 = *(s32 *)(base + 0x38);
    key3 = *(s32 *)(base + 0x3C);
    func_002AFFB0(&D_004392A0, key0);
    id0 = func_002AFFB0(&D_004392A0, key1);
    id1 = func_002AFFB0(&D_004392A0, key2);
    id2 = func_002AFFB0(&D_004392A0, key3);
    n1 = func_00359440(&D_00421AD0, id0, 0, 0, 0, 0, -1, 0);
    n2 = func_00359440(&D_00421AD0, id1, 0, 0, 0, 0, -1, 0);
    n3 = func_00359440(&D_00421AD0, id2, 0, 0, 0, 0, -1, 0);
    if (n1 > 0 && n2 > 0 && n3 > 0) {
        return 1;
    }
    return 0;
}
