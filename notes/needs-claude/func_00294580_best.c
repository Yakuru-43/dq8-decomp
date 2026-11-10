// range: 0x294580 0x2946D0
#include "common.h"

struct Slot;
M2C_UNK func_002AFFB0();
M2C_UNK func_00297BA0(s32, s32, s32, s32, s32, s32, struct Slot *, u64,
                      u64);
extern M2C_UNK D_004392A0 __attribute__((section(".data")));

struct Slot {                                           /* size 0x34 */
    s32 slot;
    s32 minus;
    s32 key;
    u8 selected;
    u8 spare;
    char payload[0x26];
};

/* ask the name table about the unit's two slots, then reserve both through
   the stream manager; 1 if the reservation took */
s32 func_00294580(s32 arg0) {
    s32 obj;
    s32 t;
    u64 flag;
    s32 count;
    s32 i;
    s32 sub;
    s32 e0;
    s32 id;
    s32 x10;
    s32 x12;
    s32 slotOff;
    s32 slot;
    s32 ret;
    s32 key;
    struct Slot slots[2];
    s32 result;

    obj = *(s32 *)(arg0 + 0x58C);
    sub = obj + 0xE0;
    t = *(s32 *)(obj + 0x364);
    flag = 1;
    if (t != 0) {
        if (*(u8 *)(t + 0x60) == 0) {
            flag = 0;
        }
    }
    count = 0;
    e0 = *(s32 *)sub;
    i = 0;
    id = *(s32 *)obj;
    x10 = *(s16 *)(obj + 0x10);
    x12 = *(s16 *)(obj + 0x12);
    while (i < 2) {
        slotOff = i << 3;
        slot = *(s32 *)(sub + 0x288) + slotOff;
        ret = func_002AFFB0(&D_004392A0, *(s32 *)(slot + 0x30));
        key = *(s32 *)(*(s32 *)(sub + 0x288) + slotOff + 0x34);
        if (key == 0) {
            break;
        }
        count++;
        slots[i].slot = ret;
        slots[i].minus = -1;
        slots[i].key = key;
        slots[i].selected = 0;
        slots[i].spare = 0;
        i++;
    }
    result = func_00297BA0(arg0, e0, id, x10, x12, count, slots, flag, flag);
    if (result <= 0) {
        return 0;
    }
    return 1;
}
