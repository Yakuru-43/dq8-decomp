// range: 0x13F780 0x13F980
// best attempt 2026-10-26 factory-1, CLASS structural score=128 (508 vs 500 B)
#include "common.h"

M2C_UNK func_0015BF80();                         /* extern */
M2C_UNK func_00157DE0();                         /* extern */
extern void func_00158140(void *, s64 *);
M2C_UNK func_00157860();                         /* extern */
M2C_UNK func_00157B30();                         /* extern */
M2C_UNK func_00157A40();                         /* extern */
M2C_UNK func_00157990();                         /* extern */
extern void func_00157930(void *, s32);
M2C_UNK func_001578D0();                         /* extern */

/* Init the stream object: build the node at +0x10 and the sub-object at
 * +0x78, latch the extents from the source record, pick the position mode
 * and raise the ready flags. */
void func_0013F780(void *o, s32 mode, void *st) {
    M2C_FIELD(o, s32 *, 0) = mode;
    M2C_FIELD(o, s32 *, 4) = 0;
    M2C_FIELD(o, s32 *, 0xE8) = 1;
    func_0015BF80((char *)o + 0x78);
    func_00157DE0((char *)o + 0x10);
    func_00158140(st, (s64 *)((char *)o + 0x40));
    func_00157860((char *)o + 0x10, (char *)st + 0x80);
    M2C_FIELD(o, s32 *, 0x128) = M2C_FIELD(st, s32 *, 0xC) << 4;
    M2C_FIELD(o, s32 *, 0x12C) = M2C_FIELD(st, s32 *, 0x10) << 4;
    M2C_FIELD(o, s32 *, 0x130) = M2C_FIELD(st, s32 *, 0x4) << 4;
    M2C_FIELD(o, s32 *, 0x134) = M2C_FIELD(st, s32 *, 0x8) << 4;
    M2C_FIELD(o, s32 *, 0x11C) = 0;
    if (M2C_FIELD(o, s32 *, 0x11C) == 1) {
        M2C_FIELD(o, s32 *, 0x124) = 0;
        M2C_FIELD(o, s32 *, 0x120) = 0;
    } else if (M2C_FIELD(o, s32 *, 0x11C) == 2) {
        M2C_FIELD(o, s32 *, 0x120) = M2C_FIELD(o, s32 *, 0x128);
        M2C_FIELD(o, s32 *, 0x124) = M2C_FIELD(o, s32 *, 0x12C);
    } else {
        M2C_FIELD(o, s32 *, 0x120) =
            M2C_FIELD(o, s32 *, 0x128) - M2C_FIELD(o, s32 *, 0x130) / 2;
        M2C_FIELD(o, s32 *, 0x124) =
            M2C_FIELD(o, s32 *, 0x12C) - M2C_FIELD(o, s32 *, 0x134) / 2;
    }
    func_00157B30((char *)o + 0x10, 1, M2C_FIELD(o, u8 *, 0x70));
    M2C_FIELD(o, u8 *, 0x70) = (M2C_FIELD(o, u8 *, 0x70) & ~0x40) | 0x40;
    func_00157A40((char *)o + 0x10, 0);
    func_00157990((char *)o + 0x10, 2);
    M2C_FIELD(o, s32 *, 0xE4) = 1;
    func_00157930((char *)o + 0x10, M2C_FIELD(o, s32 *, 0xE4));
    func_001578D0((char *)o + 0x10, 0);
    M2C_FIELD(o, u8 *, 0x70) = (M2C_FIELD(o, u8 *, 0x70) & ~0x10) | 0x10;
    M2C_FIELD(o, u8 *, 0x71) = (M2C_FIELD(o, u8 *, 0x71) & ~0x2) | 0x1;
    M2C_FIELD(o, s32 *, 0xE0) = 1;
    M2C_FIELD(o, u8 *, 0x70) = (M2C_FIELD(o, u8 *, 0x70) & ~0x8) | 0x8;
    M2C_FIELD(o, u8 *, 0x70) = (M2C_FIELD(o, u8 *, 0x70) & ~0x80) | 0x80;
    M2C_FIELD(o, u8 *, 0x70) = (M2C_FIELD(o, u8 *, 0x70) & ~0x20) | 0x20;
}
